# -*- coding: utf-8 -*-

# Automatically generated - don't edit.
# Use `python setup.py build_ui` to update it.

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_Form(object):
    def setupUi(self, Form):
        Form.setObjectName("Form")
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Ignored, QtWidgets.QSizePolicy.Ignored)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(Form.sizePolicy().hasHeightForWidth())
        Form.setSizePolicy(sizePolicy)
        self.verticalLayout = QtWidgets.QVBoxLayout(Form)
        self.verticalLayout.setObjectName("verticalLayout")
        self.groupBox = QtWidgets.QGroupBox(Form)
        self.groupBox.setObjectName("groupBox")
        self.formLayout = QtWidgets.QFormLayout(self.groupBox)
        self.formLayout.setFieldGrowthPolicy(QtWidgets.QFormLayout.AllNonFixedFieldsGrow)
        self.formLayout.setObjectName("formLayout")
        self.n_clust_label = QtWidgets.QLabel(self.groupBox)
        self.n_clust_label.setObjectName("n_clust_label")
        self.formLayout.setWidget(0, QtWidgets.QFormLayout.LabelRole, self.n_clust_label)
        self.n_clust_spin = QtWidgets.QSpinBox(self.groupBox)
        self.n_clust_spin.setObjectName("n_clust_spin")
        self.formLayout.setWidget(0, QtWidgets.QFormLayout.FieldRole, self.n_clust_spin)
        self.n_runs_label = QtWidgets.QLabel(self.groupBox)
        self.n_runs_label.setObjectName("n_runs_label")
        self.formLayout.setWidget(1, QtWidgets.QFormLayout.LabelRole, self.n_runs_label)
        self.n_runs_spin = QtWidgets.QSpinBox(self.groupBox)
        self.n_runs_spin.setObjectName("n_runs_spin")
        self.formLayout.setWidget(1, QtWidgets.QFormLayout.FieldRole, self.n_runs_spin)
        self.affinity_label = QtWidgets.QLabel(self.groupBox)
        self.affinity_label.setObjectName("affinity_label")
        self.formLayout.setWidget(2, QtWidgets.QFormLayout.LabelRole, self.affinity_label)
        self.affinity_comboBox = QtWidgets.QComboBox(self.groupBox)
        self.affinity_comboBox.setObjectName("affinity_comboBox")
        self.affinity_comboBox.addItem("")
        self.affinity_comboBox.addItem("")
        self.affinity_comboBox.addItem("")
        self.affinity_comboBox.addItem("")
        self.affinity_comboBox.addItem("")
        self.affinity_comboBox.addItem("")
        self.formLayout.setWidget(2, QtWidgets.QFormLayout.FieldRole, self.affinity_comboBox)
        self.gamma_label = QtWidgets.QLabel(self.groupBox)
        self.gamma_label.setObjectName("gamma_label")
        self.formLayout.setWidget(3, QtWidgets.QFormLayout.LabelRole, self.gamma_label)
        self.gamma_dspin = QtWidgets.QDoubleSpinBox(self.groupBox)
        self.gamma_dspin.setObjectName("gamma_dspin")
        self.formLayout.setWidget(3, QtWidgets.QFormLayout.FieldRole, self.gamma_dspin)
        self.n_neighbors_label = QtWidgets.QLabel(self.groupBox)
        self.n_neighbors_label.setObjectName("n_neighbors_label")
        self.formLayout.setWidget(4, QtWidgets.QFormLayout.LabelRole, self.n_neighbors_label)
        self.n_neighbors_spin = QtWidgets.QSpinBox(self.groupBox)
        self.n_neighbors_spin.setObjectName("n_neighbors_spin")
        self.formLayout.setWidget(4, QtWidgets.QFormLayout.FieldRole, self.n_neighbors_spin)
        self.coef0_label = QtWidgets.QLabel(self.groupBox)
        self.coef0_label.setObjectName("coef0_label")
        self.formLayout.setWidget(5, QtWidgets.QFormLayout.LabelRole, self.coef0_label)
        self.coef0_spin = QtWidgets.QDoubleSpinBox(self.groupBox)
        self.coef0_spin.setObjectName("coef0_spin")
        self.formLayout.setWidget(5, QtWidgets.QFormLayout.FieldRole, self.coef0_spin)
        self.degree_label = QtWidgets.QLabel(self.groupBox)
        self.degree_label.setObjectName("degree_label")
        self.formLayout.setWidget(6, QtWidgets.QFormLayout.LabelRole, self.degree_label)
        self.degree_spin = QtWidgets.QSpinBox(self.groupBox)
        self.degree_spin.setObjectName("degree_spin")
        self.formLayout.setWidget(6, QtWidgets.QFormLayout.FieldRole, self.degree_spin)
        self.verticalLayout.addWidget(self.groupBox)

        self.retranslateUi(Form)
        QtCore.QMetaObject.connectSlotsByName(Form)

    def retranslateUi(self, Form):
        _translate = QtCore.QCoreApplication.translate
        Form.setWindowTitle(("Form"))
        self.n_clust_label.setText(("# of clusters"))
        self.n_runs_label.setText(("# of runs"))
        self.affinity_label.setText(("Affinity kernel"))
        self.affinity_comboBox.setItemText(0, ("Radial Basis Function"))
        self.affinity_comboBox.setItemText(1, ("Nearest Neighbors"))
        self.affinity_comboBox.setItemText(2, ("Sigmoid"))
        self.affinity_comboBox.setItemText(3, ("Polynomial"))
        self.affinity_comboBox.setItemText(4, ("Linear"))
        self.affinity_comboBox.setItemText(5, ("Cosine"))
        self.gamma_label.setText(("Gamma"))
        self.n_neighbors_label.setText(("# neighbors"))
        self.coef0_label.setText(("Zero Coefficient"))
        self.degree_label.setText(("Degree"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    Form = QtWidgets.QWidget()
    ui = Ui_Form()
    ui.setupUi(Form)
    Form.show()
    sys.exit(app.exec_())

