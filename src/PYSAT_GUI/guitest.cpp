

/* Author: ngf4
 * This program will make it easier to analyze data
 * This program will take away the need to have terminal to do all the work
 * However, it should be noted that the program will output a terminal window
 * in which work will be done through, however it will not require user input
 * unless otherwise told.
 *
 *           |--------------------------------------- this is a label it doesn't do anything
 *           |        |------------------------------ this value will be spinleft it will have values ranging from 0 to 99
 *           |        |            |----------------- this value will be spinright it will have values ranging from 0 to 99
 *           v        v            v
 *    |-------------------------------------------|
 *    |    value1 [         ] [         ]         | <- There are 8 of each; label, spinleft, spinright.
 *    |                         add value         | <- each of these fields are hidden until the user hits the add value button
 *    |                                           | -> Personal Note: Check to see if the user has increased "push++"
 *    |                                           |    if they had, then take the values entered in the boxes and write it to the
 *    |-------------------------------------------|    python file.
 *
 *    TODO: add the ability to show buttons for normalization these are a bunch of lists that parse
 *    each item and then will be setVisibile to false so they aren't there until you click a button
 */

/*************** GUI Interface **************
 *     |-----------------------------------|
 *     |   Maskfile               [..]     | <- on_toolButton_clicked  ; this will open a dialog to look for the .csv mask file
 *     |   Unknown Data           [..]     | <- on_toolButton_2_clicked; this will open a dialog to look for the .csv unknown data file
 *     |   Full Database          [..]     | <- on_toolButton_3_clicked; this will open a dialog to look for the .csv full database file
 *     |   Output Location        [..]     | <- on_toolButton_4_clicked; this will open a dialog to look for a directory that you'd like
 *     |                                   |                             to output your images to
 *     |                                   |
 *     .                                   .
 *     .                            [ok]   . <- on_pushButton_clicked; this will create the final py file
 *     |-----------------------------------|
 *
 */



#include "guitest.h"
#include "ui_guitest.h"
#include <QString>
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QRect>
#include <QDesktopWidget>
#include <QSignalMapper>
#include <QFile>
#include <QTextStream>

//Global variables
int isNormFilled = 0;
int isSpinBoxFilled = 0;
int norm_push = 0;
int norm_size = 7;
int spinArray1[16] = {0,0,0,0,
                      0,0,0,0,
                      0,0,0,0,
                      0,0,0,0
                     };
QString python_file = "";
QString output_location = "";
QFile file("out.py");
QTextStream out(&file);


GuiTest::GuiTest (QWidget *parent):
    QMainWindow(parent), ui(new Ui::GuiTest){
    ui->setupUi(this);
    setSizeOfWindow();
    setupQSpinWidgets();
    setupOutFile();
}

GuiTest::~GuiTest(){
    delete ui;
}


void GuiTest::setupQSpinWidgets(){
    QList<QSpinBox*> spinBoxes= findChildren<QSpinBox*>();
    QSignalMapper* signalMapper= new QSignalMapper(this);
    QSpinBox* spinBox;
    foreach(spinBox, spinBoxes){
        connect(spinBox, SIGNAL(valueChanged(int)), signalMapper, SLOT(map()));
        signalMapper->setMapping(spinBox, spinBox);
    }
    connect(signalMapper, SIGNAL(mapped(QWidget*)), this, SLOT(spinboxWrite(QWidget*)));
}


void GuiTest::setSizeOfWindow(){
    QRect rect = QApplication::desktop()->screenGeometry();
    int height = rect.height();
    this->resize(this->width(), height*0.9);
    for (int i = 0; i < norm_size; i++){
        setNormValuesVisible(i, false);
    }
}


void GuiTest::setupOutFile(){
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << "from pysat.spectral.spectral_data import spectral_data\n";
    out << "from pysat.regression.pls_sm import pls_sm\n";
    out << "import pandas as pd\n";
}

void GuiTest::setNormValuesVisible(int index, bool visible){
    QLabel* labels[norm_size] = {ui->norm_label_2,
                                 ui->norm_label_3,
                                 ui->norm_label_4,
                                 ui->norm_label_5,
                                 ui->norm_label_6,
                                 ui->norm_label_7,
                                 ui->norm_label_8};
    QSpinBox* spinright[norm_size] = {ui->norm_spinBox_2,
                                      ui->norm_spinBox_3,
                                      ui->norm_spinBox_4,
                                      ui->norm_spinBox_5,
                                      ui->norm_spinBox_6,
                                      ui->norm_spinBox_7,
                                      ui->norm_spinBox_8};
    QSpinBox* spinleft[norm_size] = {ui->norm_spinBox_10,
                                     ui->norm_spinBox_11,
                                     ui->norm_spinBox_12,
                                     ui->norm_spinBox_13,
                                     ui->norm_spinBox_14,
                                     ui->norm_spinBox_15,
                                     ui->norm_spinBox_16};
    labels[index]->setVisible(visible);
    spinright[index]->setVisible(visible);
    spinleft[index]->setVisible(visible);

}

void GuiTest::on_maskFileButton_clicked(){
    const QString &file_name = QFileDialog::getOpenFileName(this, "Select Maskfile", QDir::homePath());
    ui->lineEdit->setText(file_name);
    out << "maskfile = \"" << file_name << "\"\n";
    isNormFilled++;
}

void GuiTest::on_unknownDataButton_clicked(){
    const QString &file_name = QFileDialog::getOpenFileName(this, "Select Unknwon Data File", QDir::homePath());
    ui->lineEdit_2->setText(file_name);
    out << "unknowndatacsv = \"" << file_name << "\"\n";
    isNormFilled++;
}

void GuiTest::on_fullDataBaseButton_clicked(){
    const QString &file_name = QFileDialog::getOpenFileName(this, "Select Database File", QDir::homePath());
    ui->lineEdit_3->setText(file_name);
    out << "db = \"" << file_name << "\"\n";
    isNormFilled++;
}

void GuiTest::on_outPutLocationButton_clicked(){
    output_location = QFileDialog::getExistingDirectory(this, "Select Output Directory", QDir::homePath());
    ui->lineEdit_4->setText(output_location);
    out << "outpath = \"" << output_location << "\"\n";
    isNormFilled++;
}

void GuiTest::on_pythonButton_clicked(){
    python_file = QFileDialog::getOpenFileName(this, "Python .exe File", QDir::rootPath());
    ui->lineEdit_6->setText(python_file);

}

/*************** GUI Interface **************/

void GuiTest::on_NormValuebutton_clicked(){ //Norm Add Value
    if (norm_push >= norm_size){
        QMessageBox::critical(this, "Warning", "Cannot add anymore values");
        return;
    } else {
        setNormValuesVisible(norm_push, true);
        norm_push++;
    }
}


int GuiTest::SpinBoxChanged(QWidget* wSp){
    QSpinBox* sp= (QSpinBox*)wSp;
    int value = sp->value();
    return value;
}

int flagBox = 0;
void GuiTest::spinboxWrite(QWidget* e){
    int spinNum = SpinBoxChanged(e);
    QString value = e->objectName();
    if (isNormFilled < 4){
        QMessageBox::critical(this, "Error", "Please add all Files");
        return;
    } else if (flagBox != 1) {
        //TODO fix this, it keeps writing over and over
        out << "data = pd.read_csv(db, header=[0, 1])\n";
        out << "data = spectral_data(data)\n";
        out << "unknown_data = pd.read_csv(unknowndatacsv, header=[0, 1])\n";
        out << "unknown_data = spectral_data(unknown_data)\n";
        out << "unknown_data.interp(data.df['wvl'].columns)\n";
        out << "data.mask(maskfile)\n";
        out << "unknown_data.mask(maskfile)\n";
        flagBox = 1;
    }

    //TODO This really needs to get fixed... Please figure out a way to get these if statements cleaned up.
    if ((value == QString::fromStdString("norm_spinBox"))){           ui->norm_spinBox_10->setMinimum(spinNum); spinArray1[0] = spinNum;
    } else if ((value == QString::fromStdString("norm_spinBox_2"))){  ui->norm_spinBox_11->setMinimum(spinNum); spinArray1[1] = spinNum;
    } else if ((value == QString::fromStdString("norm_spinBox_3"))){  ui->norm_spinBox_12->setMinimum(spinNum); spinArray1[2] = spinNum;
    } else if ((value == QString::fromStdString("norm_spinBox_4"))){  ui->norm_spinBox_13->setMinimum(spinNum); spinArray1[3] = spinNum;
    } else if ((value == QString::fromStdString("norm_spinBox_5"))){  ui->norm_spinBox_14->setMinimum(spinNum); spinArray1[4] = spinNum;
    } else if ((value == QString::fromStdString("norm_spinBox_6"))){  ui->norm_spinBox_15->setMinimum(spinNum); spinArray1[5] = spinNum;
    } else if ((value == QString::fromStdString("norm_spinBox_7"))){  ui->norm_spinBox_16->setMinimum(spinNum); spinArray1[6] = spinNum;
    } else if ((value == QString::fromStdString("norm_spinBox_8"))){                                            spinArray1[7] = spinNum;
    } else if ((value == QString::fromStdString("norm_spinBox_9"))){  ui->norm_spinBox->setMinimum(spinNum);    spinArray1[8] = spinNum;
    } else if ((value == QString::fromStdString("norm_spinBox_10"))){ ui->norm_spinBox_2->setMinimum(spinNum);  spinArray1[9] = spinNum;
    } else if ((value == QString::fromStdString("norm_spinBox_11"))){ ui->norm_spinBox_3->setMinimum(spinNum);  spinArray1[10] = spinNum;
    } else if ((value == QString::fromStdString("norm_spinBox_12"))){ ui->norm_spinBox_4->setMinimum(spinNum);  spinArray1[11] = spinNum;
    } else if ((value == QString::fromStdString("norm_spinBox_13"))){ ui->norm_spinBox_5->setMinimum(spinNum);  spinArray1[12] = spinNum;
    } else if ((value == QString::fromStdString("norm_spinBox_14"))){ ui->norm_spinBox_6->setMinimum(spinNum);  spinArray1[13] = spinNum;
    } else if ((value == QString::fromStdString("norm_spinBox_15"))){ ui->norm_spinBox_7->setMinimum(spinNum);  spinArray1[14] = spinNum;
    } else if ((value == QString::fromStdString("norm_spinBox_16"))){ ui->norm_spinBox_8->setMinimum(spinNum);  spinArray1[15] = spinNum;
    }
    qDebug() << isSpinBoxFilled++;
}

int flagEl = 0;
void GuiTest::on_elementNameLine_editingFinished()
{
    if (isNormFilled < 4 && isSpinBoxFilled < 16){
        QMessageBox::critical(this, "Error", "There are items missing above. Please fill these out first.");
        return;
    } else if (flagEl != 1){
        //TODO: add output to file from the data collected from element name
        out << "el = \'"<< ui->elementNameLine->text() << "\'\n";
        flagEl = 1;
    }
}

void GuiTest::on_nfolds_test_editingFinished(){
    out << "nfolds_test = " << ui->nfolds_test->text();
}

void GuiTest::on_okButton_clicked(){
    file.close();
    system(qPrintable(python_file + " " + "out.py"));
}

void GuiTest::on_actionExit_triggered(){
    this->close();
}



void GuiTest::on_actionSave_Current_Workflow_triggered(){
    QLineEdit* normalizationLines[4] = {ui->lineEdit,
                                       ui->lineEdit_2,
                                       ui->lineEdit_3,
                                       ui->lineEdit_4};
    getAllDataLineEdit(normalizationLines);

}

void GuiTest::getAllDataLineEdit(QLineEdit* text[]){
    QString file_name = QFileDialog::getSaveFileName(this, "Open the file");
    QFile file(file_name);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..", "file not openn");
        return;
    }
    QTextStream out(&file);
    for (int i = 0; i < (sizeof(text)/sizeof(*text)); i++){
        QString qtext = text[i]->text();
        out << qtext;
    }
    file.flush();
    file.close();
}
