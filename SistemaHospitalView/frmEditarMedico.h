#pragma once

namespace SistemaHospitalView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SistemaHospitalModel;
	using namespace SistemaHospitalController;

	/// <summary>
	/// Resumen de frmEditarMedico
	/// </summary>
	public ref class frmEditarMedico : public System::Windows::Forms::Form
	{
	public:
		frmEditarMedico(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

		frmEditarMedico(Medico^ objMedico)
		{
			InitializeComponent();
			this->objMedico = objMedico;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~frmEditarMedico()
		{
			if (components)
			{
				delete components;
			}
		}


	protected:

	protected:

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ btnGrabar;
	private: System::Windows::Forms::Button^ btnCancelar;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ txtNumeroColegioMedico;
	private: System::Windows::Forms::TextBox^ txtIdMedico;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::DataGridView^ dgvEspecialidades;
	private: System::Windows::Forms::DataGridView^ dgvCertificaciones;

		   /* Este atributo se crea porque el constructor est� recibiendo un objeto del tipo Medico y
		   ese objeto hay que asignarselo a un atributo */
	private: Medico^ objMedico;
	private: System::Windows::Forms::ComboBox^ cmbTipoDocumento;
	private: System::Windows::Forms::DateTimePicker^ dtpFecNacimiento;
	private: System::Windows::Forms::TextBox^ txtApellidos;
	private: System::Windows::Forms::TextBox^ txtNumeroDocumento;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtAltura;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ txtEmail;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ txtDireccion;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::ComboBox^ cmbEstadoCivil;
	private: System::Windows::Forms::ComboBox^ cmbGenero;
	private: System::Windows::Forms::TextBox^ txtTelefonos;
	private: System::Windows::Forms::TextBox^ txtNombres;
	private: System::Windows::Forms::TextBox^ txtIdPersona;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCertificacion;


	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnGrabar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->dgvCertificaciones = (gcnew System::Windows::Forms::DataGridView());
			this->dgvEspecialidades = (gcnew System::Windows::Forms::DataGridView());
			this->txtNumeroColegioMedico = (gcnew System::Windows::Forms::TextBox());
			this->txtIdMedico = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->cmbTipoDocumento = (gcnew System::Windows::Forms::ComboBox());
			this->dtpFecNacimiento = (gcnew System::Windows::Forms::DateTimePicker());
			this->txtApellidos = (gcnew System::Windows::Forms::TextBox());
			this->txtNumeroDocumento = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtAltura = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->txtDireccion = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->cmbEstadoCivil = (gcnew System::Windows::Forms::ComboBox());
			this->cmbGenero = (gcnew System::Windows::Forms::ComboBox());
			this->txtTelefonos = (gcnew System::Windows::Forms::TextBox());
			this->txtNombres = (gcnew System::Windows::Forms::TextBox());
			this->txtIdPersona = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->colCertificacion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCertificaciones))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvEspecialidades))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->cmbTipoDocumento);
			this->groupBox1->Controls->Add(this->dtpFecNacimiento);
			this->groupBox1->Controls->Add(this->txtApellidos);
			this->groupBox1->Controls->Add(this->txtNumeroDocumento);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->txtAltura);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->txtEmail);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->txtDireccion);
			this->groupBox1->Controls->Add(this->label12);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->cmbEstadoCivil);
			this->groupBox1->Controls->Add(this->cmbGenero);
			this->groupBox1->Controls->Add(this->txtTelefonos);
			this->groupBox1->Controls->Add(this->txtNombres);
			this->groupBox1->Controls->Add(this->txtIdPersona);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label11);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(14, 14);
			this->groupBox1->Margin = System::Windows::Forms::Padding(5);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(5);
			this->groupBox1->Size = System::Drawing::Size(1461, 355);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Datos Generales del M�dico";
			// 
			// btnGrabar
			// 
			this->btnGrabar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnGrabar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGrabar->ForeColor = System::Drawing::Color::White;
			this->btnGrabar->Location = System::Drawing::Point(389, 667);
			this->btnGrabar->Margin = System::Windows::Forms::Padding(5);
			this->btnGrabar->Name = L"btnGrabar";
			this->btnGrabar->Size = System::Drawing::Size(306, 66);
			this->btnGrabar->TabIndex = 12;
			this->btnGrabar->Text = L"Grabar";
			this->btnGrabar->UseVisualStyleBackColor = false;
			this->btnGrabar->Click += gcnew System::EventHandler(this, &frmEditarMedico::btnGrabar_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnCancelar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancelar->ForeColor = System::Drawing::Color::White;
			this->btnCancelar->Location = System::Drawing::Point(820, 667);
			this->btnCancelar->Margin = System::Windows::Forms::Padding(5);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(271, 66);
			this->btnCancelar->TabIndex = 13;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = false;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &frmEditarMedico::btnCancelar_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->dgvCertificaciones);
			this->groupBox2->Controls->Add(this->dgvEspecialidades);
			this->groupBox2->Controls->Add(this->txtNumeroColegioMedico);
			this->groupBox2->Controls->Add(this->txtIdMedico);
			this->groupBox2->Controls->Add(this->label16);
			this->groupBox2->Controls->Add(this->label18);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(14, 379);
			this->groupBox2->Margin = System::Windows::Forms::Padding(5);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(5);
			this->groupBox2->Size = System::Drawing::Size(1461, 267);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Informaci�n del M�dico";
			// 
			// dgvCertificaciones
			// 
			this->dgvCertificaciones->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dgvCertificaciones->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCertificaciones->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->colCertificacion });
			this->dgvCertificaciones->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dgvCertificaciones->Location = System::Drawing::Point(556, 94);
			this->dgvCertificaciones->Name = L"dgvCertificaciones";
			this->dgvCertificaciones->RowHeadersWidth = 51;
			this->dgvCertificaciones->RowTemplate->Height = 24;
			this->dgvCertificaciones->Size = System::Drawing::Size(874, 157);
			this->dgvCertificaciones->TabIndex = 13;
			// 
			// dgvEspecialidades
			// 
			this->dgvEspecialidades->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dgvEspecialidades->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvEspecialidades->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dgvEspecialidades->Location = System::Drawing::Point(18, 94);
			this->dgvEspecialidades->Name = L"dgvEspecialidades";
			this->dgvEspecialidades->RowHeadersWidth = 51;
			this->dgvEspecialidades->RowTemplate->Height = 24;
			this->dgvEspecialidades->Size = System::Drawing::Size(438, 157);
			this->dgvEspecialidades->TabIndex = 12;
			// 
			// txtNumeroColegioMedico
			// 
			this->txtNumeroColegioMedico->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtNumeroColegioMedico->Location = System::Drawing::Point(771, 39);
			this->txtNumeroColegioMedico->Margin = System::Windows::Forms::Padding(5);
			this->txtNumeroColegioMedico->Name = L"txtNumeroColegioMedico";
			this->txtNumeroColegioMedico->Size = System::Drawing::Size(226, 34);
			this->txtNumeroColegioMedico->TabIndex = 11;
			// 
			// txtIdMedico
			// 
			this->txtIdMedico->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtIdMedico->Enabled = false;
			this->txtIdMedico->Location = System::Drawing::Point(190, 37);
			this->txtIdMedico->Margin = System::Windows::Forms::Padding(5);
			this->txtIdMedico->Name = L"txtIdMedico";
			this->txtIdMedico->Size = System::Drawing::Size(266, 34);
			this->txtIdMedico->TabIndex = 10;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(551, 42);
			this->label16->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(162, 29);
			this->label16->TabIndex = 3;
			this->label16->Text = L"Nro. Colegio :";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(13, 42);
			this->label18->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(45, 29);
			this->label18->TabIndex = 0;
			this->label18->Text = L"Id :";
			// 
			// cmbTipoDocumento
			// 
			this->cmbTipoDocumento->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cmbTipoDocumento->FormattingEnabled = true;
			this->cmbTipoDocumento->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"DNI", L"Pasaporte", L"C.E", L"Otro" });
			this->cmbTipoDocumento->Location = System::Drawing::Point(771, 230);
			this->cmbTipoDocumento->Margin = System::Windows::Forms::Padding(5);
			this->cmbTipoDocumento->Name = L"cmbTipoDocumento";
			this->cmbTipoDocumento->Size = System::Drawing::Size(226, 37);
			this->cmbTipoDocumento->TabIndex = 36;
			this->cmbTipoDocumento->Text = L"DNI";
			// 
			// dtpFecNacimiento
			// 
			this->dtpFecNacimiento->CalendarMonthBackground = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dtpFecNacimiento->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpFecNacimiento->Location = System::Drawing::Point(266, 113);
			this->dtpFecNacimiento->MinDate = System::DateTime(1900, 1, 1, 0, 0, 0, 0);
			this->dtpFecNacimiento->Name = L"dtpFecNacimiento";
			this->dtpFecNacimiento->Size = System::Drawing::Size(217, 34);
			this->dtpFecNacimiento->TabIndex = 28;
			// 
			// txtApellidos
			// 
			this->txtApellidos->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtApellidos->Location = System::Drawing::Point(771, 51);
			this->txtApellidos->Margin = System::Windows::Forms::Padding(5);
			this->txtApellidos->Name = L"txtApellidos";
			this->txtApellidos->Size = System::Drawing::Size(226, 34);
			this->txtApellidos->TabIndex = 23;
			// 
			// txtNumeroDocumento
			// 
			this->txtNumeroDocumento->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtNumeroDocumento->Location = System::Drawing::Point(1205, 235);
			this->txtNumeroDocumento->Margin = System::Windows::Forms::Padding(5);
			this->txtNumeroDocumento->Name = L"txtNumeroDocumento";
			this->txtNumeroDocumento->Size = System::Drawing::Size(233, 34);
			this->txtNumeroDocumento->TabIndex = 37;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(23, 54);
			this->label2->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 29);
			this->label2->TabIndex = 44;
			this->label2->Text = L"Id :";
			// 
			// txtAltura
			// 
			this->txtAltura->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtAltura->Location = System::Drawing::Point(266, 294);
			this->txtAltura->Margin = System::Windows::Forms::Padding(5);
			this->txtAltura->Name = L"txtAltura";
			this->txtAltura->Size = System::Drawing::Size(217, 34);
			this->txtAltura->TabIndex = 38;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(23, 294);
			this->label10->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(86, 29);
			this->label10->TabIndex = 43;
			this->label10->Text = L"Altura :";
			// 
			// txtEmail
			// 
			this->txtEmail->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtEmail->Location = System::Drawing::Point(771, 174);
			this->txtEmail->Margin = System::Windows::Forms::Padding(5);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(667, 34);
			this->txtEmail->TabIndex = 34;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(551, 174);
			this->label9->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(86, 29);
			this->label9->TabIndex = 42;
			this->label9->Text = L"Email :";
			// 
			// txtDireccion
			// 
			this->txtDireccion->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtDireccion->Location = System::Drawing::Point(771, 111);
			this->txtDireccion->Margin = System::Windows::Forms::Padding(5);
			this->txtDireccion->Name = L"txtDireccion";
			this->txtDireccion->Size = System::Drawing::Size(667, 34);
			this->txtDireccion->TabIndex = 31;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(551, 111);
			this->label12->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(127, 29);
			this->label12->TabIndex = 40;
			this->label12->Text = L"Direcci�n :";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(551, 54);
			this->label8->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(126, 29);
			this->label8->TabIndex = 41;
			this->label8->Text = L"Apellidos :";
			// 
			// cmbEstadoCivil
			// 
			this->cmbEstadoCivil->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cmbEstadoCivil->FormattingEnabled = true;
			this->cmbEstadoCivil->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Soltero", L"Casado", L"Divorciado", L"Viudo" });
			this->cmbEstadoCivil->Location = System::Drawing::Point(266, 235);
			this->cmbEstadoCivil->Margin = System::Windows::Forms::Padding(5);
			this->cmbEstadoCivil->Name = L"cmbEstadoCivil";
			this->cmbEstadoCivil->Size = System::Drawing::Size(217, 37);
			this->cmbEstadoCivil->TabIndex = 35;
			this->cmbEstadoCivil->Text = L"Soltero";
			// 
			// cmbGenero
			// 
			this->cmbGenero->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cmbGenero->FormattingEnabled = true;
			this->cmbGenero->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Masculino", L"Femenino" });
			this->cmbGenero->Location = System::Drawing::Point(266, 171);
			this->cmbGenero->Margin = System::Windows::Forms::Padding(5);
			this->cmbGenero->Name = L"cmbGenero";
			this->cmbGenero->Size = System::Drawing::Size(217, 37);
			this->cmbGenero->TabIndex = 33;
			this->cmbGenero->Text = L"Masculino";
			// 
			// txtTelefonos
			// 
			this->txtTelefonos->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtTelefonos->Location = System::Drawing::Point(771, 289);
			this->txtTelefonos->Margin = System::Windows::Forms::Padding(5);
			this->txtTelefonos->Name = L"txtTelefonos";
			this->txtTelefonos->Size = System::Drawing::Size(667, 34);
			this->txtTelefonos->TabIndex = 39;
			// 
			// txtNombres
			// 
			this->txtNombres->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtNombres->Location = System::Drawing::Point(1205, 57);
			this->txtNombres->Margin = System::Windows::Forms::Padding(5);
			this->txtNombres->Name = L"txtNombres";
			this->txtNombres->Size = System::Drawing::Size(233, 34);
			this->txtNombres->TabIndex = 27;
			// 
			// txtIdPersona
			// 
			this->txtIdPersona->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtIdPersona->Enabled = false;
			this->txtIdPersona->Location = System::Drawing::Point(266, 56);
			this->txtIdPersona->Margin = System::Windows::Forms::Padding(5);
			this->txtIdPersona->Name = L"txtIdPersona";
			this->txtIdPersona->Size = System::Drawing::Size(217, 34);
			this->txtIdPersona->TabIndex = 22;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(551, 292);
			this->label7->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(134, 29);
			this->label7->TabIndex = 32;
			this->label7->Text = L"Tel�fonos :";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(23, 238);
			this->label6->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(141, 29);
			this->label6->TabIndex = 30;
			this->label6->Text = L"Estado civil:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(23, 171);
			this->label5->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(106, 29);
			this->label5->TabIndex = 29;
			this->label5->Text = L"G�nero :";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(551, 238);
			this->label11->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(204, 29);
			this->label11->TabIndex = 26;
			this->label11->Text = L"Tipo Documento :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(23, 111);
			this->label4->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(220, 29);
			this->label4->TabIndex = 25;
			this->label4->Text = L"Fecha Nacimiento :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1037, 59);
			this->label3->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(119, 29);
			this->label3->TabIndex = 24;
			this->label3->Text = L"Nombres:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1004, 238);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(194, 29);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Nro. Documento:";
			// 
			// colCertificacion
			// 
			this->colCertificacion->HeaderText = L"Certificaci�n";
			this->colCertificacion->MinimumWidth = 6;
			this->colCertificacion->Name = L"colCertificacion";
			this->colCertificacion->Width = 790;
			// 
			// frmEditarMedico
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1493, 765);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->btnGrabar);
			this->Controls->Add(this->btnCancelar);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"frmEditarMedico";
			this->Text = L"Sistema Gesti�n Hospitalario - M�dico - Actualizar informaci�n";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &frmEditarMedico::frmEditarMedico_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCertificaciones))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvEspecialidades))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion


	private: System::Void frmEditarMedico_Load(System::Object^ sender, System::EventArgs^ e) {
		// Configuraci�n del DateTimePicker
		this->dtpFecNacimiento->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
		this->dtpFecNacimiento->CustomFormat = "dd/MM/yyyy";
		HelperController^ helper = gcnew HelperController();

		this->txtIdPersona->Text = Convert::ToString(this->objMedico->getIdPersona());
		this->txtNombres->Text = this->objMedico->getNombres();
		this->txtApellidos->Text = this->objMedico->getApellidos();
		int iFechaNacimiento = this->objMedico->getFechaNacimiento();
		this->dtpFecNacimiento->Value = helper->intFechaToDateTime(iFechaNacimiento);
		this->cmbGenero->Text = this->objMedico->getGenero();
		this->txtDireccion->Text = this->objMedico->getDireccion();
		this->txtTelefonos->Text = this->objMedico->getTelefonos();
		this->txtEmail->Text = this->objMedico->getEmail();
		this->cmbEstadoCivil->Text = this->objMedico->getEstadoCivil();
		this->txtAltura->Text = Convert::ToString(this->objMedico->getAltura());
		this->cmbTipoDocumento->Text = this->objMedico->getTipoDocumento();
		this->txtNumeroDocumento->Text = this->objMedico->getNumeroDocumento();

		this->txtIdMedico->Text = Convert::ToString(this->objMedico->getIdMedico());
		this->txtNumeroColegioMedico->Text = this->objMedico->getNumeroColegioMedico();

		//Listamos las Certificaciones
		List<String^>^ listaCertificados = this->objMedico->getCertificaciones();
		for each (String ^ certificado in listaCertificados) {
			this->dgvCertificaciones->Rows->Add(certificado);
		}

		// Crear una nueva columna ComboBox
		DataGridViewComboBoxColumn^ comboBoxColumn = gcnew DataGridViewComboBoxColumn();
		comboBoxColumn->HeaderText = "Especialidad";
		comboBoxColumn->Name = "colEspecialidad";
		comboBoxColumn->Width = 350;
		//Listamos las Especialidades desde el archivo Especialidades.txt
		EspecialidadController^ especialidadController = gcnew EspecialidadController();
		List<Especialidad^>^ listaCmb = especialidadController->listarEspecialidades();
		for each (Especialidad ^ objeto in listaCmb) {
			comboBoxColumn->Items->Add(objeto->getNombre());
		}
		//O se puede listar directamente en duro:
		//comboBoxColumn->Items->AddRange(gcnew array<String^> { "Cardiolog�a", "Cirug�a General", "Dermatolog�a", "Endocrinolog�a", "Gastroenterolog�a", "Geriatr�a", "Ginecolog�a", "Medicina de Urgencias", "Medicina Interna", "Nefrolog�a", "Neumolog�a", "Neurolog�a", "Oftalmolog�a", "Oncolog�a", "Ortopedia", "Otorrinolaringolog�a", "Pediatr�a", "Psiquiatr�a", "Reumatolog�a", "Urolog�a" });
		this->dgvEspecialidades->Columns->Add(comboBoxColumn);
		//Listamos las Especialidades
		List<Especialidad^>^ listaEspecialidades = this->objMedico->getEspecialidades();
		for each (Especialidad ^ objEspecialidad in listaEspecialidades) {
			this->dgvEspecialidades->Rows->Add(objEspecialidad->getNombre());
		}
	}
	
	private: System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void btnGrabar_Click(System::Object^ sender, System::EventArgs^ e) {
		HelperController^ helper = gcnew HelperController();

		int idPersona = Convert::ToInt32(this->txtIdPersona->Text);
		String^ nombres = this->txtNombres->Text;
		String^ apellidos = this->txtApellidos->Text;
		DateTime dFechaNacimiento = this->dtpFecNacimiento->Value; //retorna la fecha
		//Le damos el formato deseado INT: yyyyMMdd
		int iFechaNacimiento = helper->dateTimeTointFecha(dFechaNacimiento);
		String^ genero = this->cmbGenero->Text;
		String^ direccion = this->txtDireccion->Text;
		String^ telefonos = this->txtTelefonos->Text;
		String^ email = this->txtEmail->Text;
		String^ estadoCivil = this->cmbEstadoCivil->Text;
		double altura = Convert::ToDouble(this->txtAltura->Text);
		String^ tipoDocumento = this->cmbTipoDocumento->Text;
		String^ numeroDocumento = this->txtNumeroDocumento->Text;

		int idMedico = Convert::ToInt32(this->txtIdMedico->Text);
		String^ numeroColegioMedico = this->txtNumeroColegioMedico->Text;
		
		//Lista de Certificaciones
		List<String^>^ certificaciones = gcnew List<String^>();
		if (this->dgvCertificaciones->Rows->Count > 0) {
			//No esta vacio
			for (int i = 0; i < dgvCertificaciones->Rows->Count; i++) {
				// Verificar si la fila no est� vac�a (por ejemplo, si no tiene celdas nulas)
				if (dgvCertificaciones->Rows[i]->Cells[0]->Value != nullptr) {
					String^ resultado = dgvCertificaciones->Rows[i]->Cells[0]->Value->ToString();
					certificaciones->Add(resultado);
				}
			}
		}

		EspecialidadController^ especialidadController = gcnew EspecialidadController();
		List<Especialidad^>^ especialidades = gcnew List<Especialidad^>();
		if (this->dgvEspecialidades->Rows->Count > 0) {
			//No esta vacio
			// Listar todas las especialidades registradas
			for (int i = 0; i < dgvEspecialidades->Rows->Count; i++) {
				// Verificar si la fila no est� vac�a (por ejemplo, si no tiene celdas nulas)
				if (dgvEspecialidades->Rows[i]->Cells[0]->Value != nullptr) {
					String^ sEspecialidad = dgvEspecialidades->Rows[i]->Cells[0]->Value->ToString();
					especialidades->Add(especialidadController->buscarEspecialidadByNombre(sEspecialidad));
				}
			}
		}

		List<int>^ idCitasAsignadas = gcnew List<int>();
		List<Paciente^>^ pacientesAsociados = gcnew List<Paciente^>();

		MedicoController^ objMedico = gcnew MedicoController();
		//Procedimiento con archivo plano
		//objMedico->modificarMedico(idPersona, nombre, edad, genero, direccion, telefono, email, estadoCivil, altura, idMedico, numeroColegioMedico, certificaciones, especialidades, idCitasAsignadas, pacientesAsociados);
		String^ sMessageBox = objMedico->updateMedico(idPersona, apellidos, nombres, iFechaNacimiento, genero, direccion, telefonos, email, estadoCivil, altura, tipoDocumento, numeroDocumento, idMedico, numeroColegioMedico, certificaciones, especialidades, idCitasAsignadas, pacientesAsociados);
		if (sMessageBox->Equals(""))
		{
			MessageBox::Show("La informaci�n del M�dico ha sido actualizado con �xito...!", "Actualizaci�n Exitosa",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close();
		}
		else
		{
			MessageBox::Show(sMessageBox, "Error en Actualizaci�n", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
};
}
