#pragma once

namespace SistemaHospitalView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SistemaHospitalModel;
	using namespace SistemaHospitalController;

	/// <summary>
	/// Resumen de frmDetalleCita
	/// </summary>
	public ref class frmDetalleCita : public System::Windows::Forms::Form
	{
	public:
		frmDetalleCita(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

		frmDetalleCita(Cita^ objCita)
		{
			InitializeComponent();
			this->objCita = objCita;
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmDetalleCita()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtPaciente;
	private: System::Windows::Forms::TextBox^ txtMedico;
	private: System::Windows::Forms::TextBox^ txtFecha;
	private: System::Windows::Forms::TextBox^ txtHora;
	private: System::Windows::Forms::Button^ btnCerrar;






		   /* Este atributo se crea porque el constructor está recibiendo un objeto del tipo Cita y
		   ese objeto hay que asignarselo a un atributo */
	private: Cita^ objCita;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtPaciente = (gcnew System::Windows::Forms::TextBox());
			this->txtMedico = (gcnew System::Windows::Forms::TextBox());
			this->txtFecha = (gcnew System::Windows::Forms::TextBox());
			this->txtHora = (gcnew System::Windows::Forms::TextBox());
			this->btnCerrar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(57, 38);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(119, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Paciente :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(57, 103);
			this->label2->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(105, 29);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Medico :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(57, 171);
			this->label3->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(92, 29);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Fecha :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(57, 236);
			this->label4->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(77, 29);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Hora :";
			// 
			// txtPaciente
			// 
			this->txtPaciente->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtPaciente->Location = System::Drawing::Point(261, 35);
			this->txtPaciente->Margin = System::Windows::Forms::Padding(5);
			this->txtPaciente->Name = L"txtPaciente";
			this->txtPaciente->Size = System::Drawing::Size(480, 34);
			this->txtPaciente->TabIndex = 4;
			// 
			// txtMedico
			// 
			this->txtMedico->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtMedico->Location = System::Drawing::Point(261, 100);
			this->txtMedico->Margin = System::Windows::Forms::Padding(5);
			this->txtMedico->Name = L"txtMedico";
			this->txtMedico->Size = System::Drawing::Size(480, 34);
			this->txtMedico->TabIndex = 5;
			// 
			// txtFecha
			// 
			this->txtFecha->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtFecha->Location = System::Drawing::Point(261, 168);
			this->txtFecha->Margin = System::Windows::Forms::Padding(5);
			this->txtFecha->Name = L"txtFecha";
			this->txtFecha->Size = System::Drawing::Size(203, 34);
			this->txtFecha->TabIndex = 6;
			// 
			// txtHora
			// 
			this->txtHora->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtHora->Location = System::Drawing::Point(261, 233);
			this->txtHora->Margin = System::Windows::Forms::Padding(5);
			this->txtHora->Name = L"txtHora";
			this->txtHora->Size = System::Drawing::Size(203, 34);
			this->txtHora->TabIndex = 7;
			// 
			// btnCerrar
			// 
			this->btnCerrar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnCerrar->ForeColor = System::Drawing::Color::White;
			this->btnCerrar->Location = System::Drawing::Point(323, 314);
			this->btnCerrar->Margin = System::Windows::Forms::Padding(5);
			this->btnCerrar->Name = L"btnCerrar";
			this->btnCerrar->Size = System::Drawing::Size(164, 53);
			this->btnCerrar->TabIndex = 8;
			this->btnCerrar->Text = L"Cerrar";
			this->btnCerrar->UseVisualStyleBackColor = false;
			this->btnCerrar->Click += gcnew System::EventHandler(this, &frmDetalleCita::btnCerrar_Click);
			// 
			// frmDetalleCita
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(807, 408);
			this->Controls->Add(this->btnCerrar);
			this->Controls->Add(this->txtHora);
			this->Controls->Add(this->txtFecha);
			this->Controls->Add(this->txtMedico);
			this->Controls->Add(this->txtPaciente);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"frmDetalleCita";
			this->Text = L"Detalle Cita";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &frmDetalleCita::frmDetalleCita_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmDetalleCita_Load(System::Object^ sender, System::EventArgs^ e) {
		this->txtPaciente->Text = this->objCita->getPaciente()->getNombres();
		this->txtMedico->Text = this->objCita->getMedico()->getNombres();
		this->txtFecha->Text = imprimirFechabyInt(this->objCita->getFecha());
		this->txtHora->Text = this->objCita->getHora();
	}
		   /*METODOSPERSONALES*/
	public: String^ imprimirFechabyInt(int iFecha) {
		// Extraer año, mes y día
		int anio = iFecha / 10000;
		int mes = (iFecha / 100) % 100;
		int dia = iFecha % 100;
		return String::Format("{0:D2}/{1:D2}/{2}", dia, mes, anio);
	}
	private: System::Void btnCerrar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
