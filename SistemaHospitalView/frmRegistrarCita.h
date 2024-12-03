#pragma once
#include "frmBuscarPaciente.h"
#include "frmBuscarMedico.h"

namespace SistemaHospitalView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SistemaHospitalController;
	using namespace SistemaHospitalModel;

	/// <summary>
	/// Resumen de frmRegistrarCita
	/// </summary>
	public ref class frmRegistrarCita : public System::Windows::Forms::Form
	{
	public:
		frmRegistrarCita(void)
		{
			InitializeComponent();
			this->paciente = nullptr;
			this->medico = nullptr;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmRegistrarCita()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ txtHora;
	protected:

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DateTimePicker^ dtpFecha;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ btnBuscarPaciente;

	private: System::Windows::Forms::TextBox^ txtPaciente;

	private: System::Windows::Forms::TextBox^ txtIdPaciente;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Button^ btnBuscarMedico;

	private: System::Windows::Forms::TextBox^ txtMedico;

	private: System::Windows::Forms::TextBox^ txtIdMedico;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ btnGrabar;
	private: System::Windows::Forms::Button^ btnCancelar;

	private: Paciente^ paciente;
	private: Medico^ medico;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->txtHora = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dtpFecha = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->btnBuscarPaciente = (gcnew System::Windows::Forms::Button());
			this->txtPaciente = (gcnew System::Windows::Forms::TextBox());
			this->txtIdPaciente = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->btnBuscarMedico = (gcnew System::Windows::Forms::Button());
			this->txtMedico = (gcnew System::Windows::Forms::TextBox());
			this->txtIdMedico = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->btnGrabar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->txtHora);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->dtpFecha);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(26, 28);
			this->groupBox1->Margin = System::Windows::Forms::Padding(5);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(5);
			this->groupBox1->Size = System::Drawing::Size(809, 125);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Datos de la Cita";
			// 
			// txtHora
			// 
			this->txtHora->Location = System::Drawing::Point(579, 62);
			this->txtHora->Margin = System::Windows::Forms::Padding(5);
			this->txtHora->Name = L"txtHora";
			this->txtHora->Size = System::Drawing::Size(164, 34);
			this->txtHora->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(483, 68);
			this->label3->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 29);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Hora :";
			// 
			// dtpFecha
			// 
			this->dtpFecha->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpFecha->Location = System::Drawing::Point(184, 63);
			this->dtpFecha->Margin = System::Windows::Forms::Padding(5);
			this->dtpFecha->Name = L"dtpFecha";
			this->dtpFecha->Size = System::Drawing::Size(183, 34);
			this->dtpFecha->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(28, 65);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Fecha :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(28, 54);
			this->label2->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(104, 29);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Código :";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->btnBuscarPaciente);
			this->groupBox2->Controls->Add(this->txtPaciente);
			this->groupBox2->Controls->Add(this->txtIdPaciente);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Location = System::Drawing::Point(26, 163);
			this->groupBox2->Margin = System::Windows::Forms::Padding(5);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(5);
			this->groupBox2->Size = System::Drawing::Size(809, 184);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Datos del Paciente";
			// 
			// btnBuscarPaciente
			// 
			this->btnBuscarPaciente->Location = System::Drawing::Point(579, 42);
			this->btnBuscarPaciente->Margin = System::Windows::Forms::Padding(5);
			this->btnBuscarPaciente->Name = L"btnBuscarPaciente";
			this->btnBuscarPaciente->Size = System::Drawing::Size(164, 53);
			this->btnBuscarPaciente->TabIndex = 6;
			this->btnBuscarPaciente->Text = L"Buscar";
			this->btnBuscarPaciente->UseVisualStyleBackColor = true;
			this->btnBuscarPaciente->Click += gcnew System::EventHandler(this, &frmRegistrarCita::btnBuscarPaciente_Click);
			// 
			// txtPaciente
			// 
			this->txtPaciente->Enabled = false;
			this->txtPaciente->Location = System::Drawing::Point(270, 117);
			this->txtPaciente->Margin = System::Windows::Forms::Padding(5);
			this->txtPaciente->Name = L"txtPaciente";
			this->txtPaciente->Size = System::Drawing::Size(473, 34);
			this->txtPaciente->TabIndex = 5;
			// 
			// txtIdPaciente
			// 
			this->txtIdPaciente->Enabled = false;
			this->txtIdPaciente->Location = System::Drawing::Point(270, 51);
			this->txtIdPaciente->Margin = System::Windows::Forms::Padding(5);
			this->txtIdPaciente->Name = L"txtIdPaciente";
			this->txtIdPaciente->Size = System::Drawing::Size(269, 34);
			this->txtIdPaciente->TabIndex = 4;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(28, 120);
			this->label4->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(224, 29);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Nombre Completo :";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->btnBuscarMedico);
			this->groupBox3->Controls->Add(this->txtMedico);
			this->groupBox3->Controls->Add(this->txtIdMedico);
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Controls->Add(this->label6);
			this->groupBox3->Location = System::Drawing::Point(26, 357);
			this->groupBox3->Margin = System::Windows::Forms::Padding(5);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(5);
			this->groupBox3->Size = System::Drawing::Size(809, 188);
			this->groupBox3->TabIndex = 7;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Datos del Médico";
			// 
			// btnBuscarMedico
			// 
			this->btnBuscarMedico->Location = System::Drawing::Point(579, 39);
			this->btnBuscarMedico->Margin = System::Windows::Forms::Padding(5);
			this->btnBuscarMedico->Name = L"btnBuscarMedico";
			this->btnBuscarMedico->Size = System::Drawing::Size(164, 53);
			this->btnBuscarMedico->TabIndex = 6;
			this->btnBuscarMedico->Text = L"Buscar";
			this->btnBuscarMedico->UseVisualStyleBackColor = true;
			this->btnBuscarMedico->Click += gcnew System::EventHandler(this, &frmRegistrarCita::btnBuscarMedico_Click);
			// 
			// txtMedico
			// 
			this->txtMedico->Enabled = false;
			this->txtMedico->Location = System::Drawing::Point(270, 109);
			this->txtMedico->Margin = System::Windows::Forms::Padding(5);
			this->txtMedico->Name = L"txtMedico";
			this->txtMedico->Size = System::Drawing::Size(473, 34);
			this->txtMedico->TabIndex = 5;
			// 
			// txtIdMedico
			// 
			this->txtIdMedico->Enabled = false;
			this->txtIdMedico->Location = System::Drawing::Point(270, 48);
			this->txtIdMedico->Margin = System::Windows::Forms::Padding(5);
			this->txtIdMedico->Name = L"txtIdMedico";
			this->txtIdMedico->Size = System::Drawing::Size(269, 34);
			this->txtIdMedico->TabIndex = 4;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(28, 123);
			this->label5->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(224, 29);
			this->label5->TabIndex = 3;
			this->label5->Text = L"Nombre Completo :";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(28, 51);
			this->label6->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(104, 29);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Código :";
			// 
			// btnGrabar
			// 
			this->btnGrabar->Location = System::Drawing::Point(229, 572);
			this->btnGrabar->Margin = System::Windows::Forms::Padding(5);
			this->btnGrabar->Name = L"btnGrabar";
			this->btnGrabar->Size = System::Drawing::Size(164, 53);
			this->btnGrabar->TabIndex = 8;
			this->btnGrabar->Text = L"Grabar";
			this->btnGrabar->UseVisualStyleBackColor = true;
			this->btnGrabar->Click += gcnew System::EventHandler(this, &frmRegistrarCita::btnGrabar_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->Location = System::Drawing::Point(479, 572);
			this->btnCancelar->Margin = System::Windows::Forms::Padding(5);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(164, 53);
			this->btnCancelar->TabIndex = 9;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = true;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &frmRegistrarCita::btnCancelar_Click);
			// 
			// frmRegistrarCita
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(873, 655);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->btnGrabar);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"frmRegistrarCita";
			this->Text = L"Registrar Cita";
			this->Load += gcnew System::EventHandler(this, &frmRegistrarCita::frmRegistrarCita_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnBuscarPaciente_Click(System::Object^ sender, System::EventArgs^ e) {
		this->paciente = gcnew Paciente();
		frmBuscarPaciente^ ventanaBuscarPaciente = gcnew frmBuscarPaciente(this->paciente);
		ventanaBuscarPaciente->ShowDialog();
		if (this->paciente)
		{
			txtIdPaciente->Text = Convert::ToString(this->paciente->getIdPaciente());
			txtPaciente->Text = this->paciente->getApellidos();
		}
	}
	private: System::Void btnBuscarMedico_Click(System::Object^ sender, System::EventArgs^ e) {
		this->medico = gcnew Medico();
		frmBuscarMedico^ ventanaBuscarMedico = gcnew frmBuscarMedico(this->medico);
		ventanaBuscarMedico->ShowDialog();
		if (this->medico)
		{
			txtIdMedico->Text = Convert::ToString(this->medico->getIdMedico());
			txtMedico->Text = this->paciente->getApellidos();
		}
	}
	private: System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnGrabar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtMedico->Text->Equals("") || txtPaciente->Text->Equals(""))
		{
			MessageBox::Show("Por favor, seleccionar un Paciente y/o Médico...!", "Error en agendar Cita", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			String^ fecha = dtpFecha->Text;
			String^ hora = txtHora->Text;
			int idPaciente = Convert::ToInt32(txtIdPaciente->Text);
			int idMedico = Convert::ToInt32(txtIdMedico->Text);

			CitaController^ citaController = gcnew CitaController();
			citaController->insertCita(idPaciente, idMedico, fecha, hora);
			MessageBox::Show("La Cita se agendo correctamente...!", "Cita agendada", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close();
		}
	}

	private: System::Void frmRegistrarCita_Load(System::Object^ sender, System::EventArgs^ e) {
		txtHora->Text = "09:00";
	}
	};
}
