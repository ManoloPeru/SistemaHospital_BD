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
	/// Resumen de frmNuevoMedico
	/// </summary>
	public ref class frmNuevoMedico : public System::Windows::Forms::Form
	{
	public:
		frmNuevoMedico(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmNuevoMedico()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox2;
	protected:
	private: System::Windows::Forms::TextBox^ txtNumeroColegioMedico;
	private: System::Windows::Forms::TextBox^ txtIdMedico;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ txtAltura;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ txtEmail;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ txtDireccion;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::ComboBox^ cmbEstadoCivil;
	private: System::Windows::Forms::ComboBox^ cmbGenero;
	private: System::Windows::Forms::TextBox^ txtTelefono;
	private: System::Windows::Forms::TextBox^ txtEdad;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::TextBox^ txtIdPersona;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnGrabar;
	private: System::Windows::Forms::Button^ btnCancelar;
	private: System::Windows::Forms::DataGridView^ dgvCertificaciones;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCertificacion;
	private: System::Windows::Forms::DataGridView^ dgvEspecialidades;

		   /* Este atributo se crea porque el constructor está recibiendo un objeto del tipo Medico y
		   ese objeto hay que asignarselo a un atributo */
	private: Medico^ objMedico;


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
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->dgvCertificaciones = (gcnew System::Windows::Forms::DataGridView());
			this->colCertificacion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgvEspecialidades = (gcnew System::Windows::Forms::DataGridView());
			this->txtNumeroColegioMedico = (gcnew System::Windows::Forms::TextBox());
			this->txtIdMedico = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->txtAltura = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->txtDireccion = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->cmbEstadoCivil = (gcnew System::Windows::Forms::ComboBox());
			this->cmbGenero = (gcnew System::Windows::Forms::ComboBox());
			this->txtTelefono = (gcnew System::Windows::Forms::TextBox());
			this->txtEdad = (gcnew System::Windows::Forms::TextBox());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->txtIdPersona = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnGrabar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCertificaciones))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvEspecialidades))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
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
			this->groupBox2->Location = System::Drawing::Point(14, 392);
			this->groupBox2->Margin = System::Windows::Forms::Padding(5);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(5);
			this->groupBox2->Size = System::Drawing::Size(1463, 302);
			this->groupBox2->TabIndex = 13;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Información del Médico";
			// 
			// dgvCertificaciones
			// 
			this->dgvCertificaciones->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dgvCertificaciones->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCertificaciones->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->colCertificacion });
			this->dgvCertificaciones->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dgvCertificaciones->Location = System::Drawing::Point(839, 121);
			this->dgvCertificaciones->Name = L"dgvCertificaciones";
			this->dgvCertificaciones->RowHeadersWidth = 51;
			this->dgvCertificaciones->RowTemplate->Height = 24;
			this->dgvCertificaciones->Size = System::Drawing::Size(599, 157);
			this->dgvCertificaciones->TabIndex = 15;
			// 
			// colCertificacion
			// 
			this->colCertificacion->HeaderText = L"Certificación";
			this->colCertificacion->MinimumWidth = 6;
			this->colCertificacion->Name = L"colCertificacion";
			this->colCertificacion->Width = 500;
			// 
			// dgvEspecialidades
			// 
			this->dgvEspecialidades->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dgvEspecialidades->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvEspecialidades->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dgvEspecialidades->Location = System::Drawing::Point(18, 121);
			this->dgvEspecialidades->Name = L"dgvEspecialidades";
			this->dgvEspecialidades->RowHeadersWidth = 51;
			this->dgvEspecialidades->RowTemplate->Height = 24;
			this->dgvEspecialidades->Size = System::Drawing::Size(455, 157);
			this->dgvEspecialidades->TabIndex = 14;
			// 
			// txtNumeroColegioMedico
			// 
			this->txtNumeroColegioMedico->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtNumeroColegioMedico->Location = System::Drawing::Point(839, 53);
			this->txtNumeroColegioMedico->Margin = System::Windows::Forms::Padding(5);
			this->txtNumeroColegioMedico->Name = L"txtNumeroColegioMedico";
			this->txtNumeroColegioMedico->Size = System::Drawing::Size(599, 34);
			this->txtNumeroColegioMedico->TabIndex = 10;
			// 
			// txtIdMedico
			// 
			this->txtIdMedico->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtIdMedico->Location = System::Drawing::Point(190, 55);
			this->txtIdMedico->Margin = System::Windows::Forms::Padding(5);
			this->txtIdMedico->Name = L"txtIdMedico";
			this->txtIdMedico->Size = System::Drawing::Size(294, 34);
			this->txtIdMedico->TabIndex = 9;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(569, 58);
			this->label16->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(162, 29);
			this->label16->TabIndex = 3;
			this->label16->Text = L"Nro. Colegio :";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(13, 60);
			this->label18->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(45, 29);
			this->label18->TabIndex = 0;
			this->label18->Text = L"Id :";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->txtAltura);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->txtEmail);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->txtDireccion);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->cmbEstadoCivil);
			this->groupBox1->Controls->Add(this->cmbGenero);
			this->groupBox1->Controls->Add(this->txtTelefono);
			this->groupBox1->Controls->Add(this->txtEdad);
			this->groupBox1->Controls->Add(this->txtNombre);
			this->groupBox1->Controls->Add(this->txtIdPersona);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(14, 14);
			this->groupBox1->Margin = System::Windows::Forms::Padding(5);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(5);
			this->groupBox1->Size = System::Drawing::Size(1463, 368);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Datos Generales del Médico";
			// 
			// txtAltura
			// 
			this->txtAltura->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtAltura->Location = System::Drawing::Point(190, 316);
			this->txtAltura->Margin = System::Windows::Forms::Padding(5);
			this->txtAltura->Name = L"txtAltura";
			this->txtAltura->Size = System::Drawing::Size(294, 34);
			this->txtAltura->TabIndex = 19;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(13, 316);
			this->label10->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(86, 29);
			this->label10->TabIndex = 18;
			this->label10->Text = L"Altura :";
			// 
			// txtEmail
			// 
			this->txtEmail->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtEmail->Location = System::Drawing::Point(839, 189);
			this->txtEmail->Margin = System::Windows::Forms::Padding(5);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(599, 34);
			this->txtEmail->TabIndex = 6;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(569, 189);
			this->label9->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(86, 29);
			this->label9->TabIndex = 16;
			this->label9->Text = L"Email :";
			// 
			// txtDireccion
			// 
			this->txtDireccion->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtDireccion->Location = System::Drawing::Point(839, 121);
			this->txtDireccion->Margin = System::Windows::Forms::Padding(5);
			this->txtDireccion->Name = L"txtDireccion";
			this->txtDireccion->Size = System::Drawing::Size(599, 34);
			this->txtDireccion->TabIndex = 4;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(569, 121);
			this->label8->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(127, 29);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Dirección :";
			// 
			// cmbEstadoCivil
			// 
			this->cmbEstadoCivil->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cmbEstadoCivil->FormattingEnabled = true;
			this->cmbEstadoCivil->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Soltero", L"Casado", L"Divorciado", L"Viudo" });
			this->cmbEstadoCivil->Location = System::Drawing::Point(190, 250);
			this->cmbEstadoCivil->Margin = System::Windows::Forms::Padding(5);
			this->cmbEstadoCivil->Name = L"cmbEstadoCivil";
			this->cmbEstadoCivil->Size = System::Drawing::Size(294, 37);
			this->cmbEstadoCivil->TabIndex = 7;
			// 
			// cmbGenero
			// 
			this->cmbGenero->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cmbGenero->FormattingEnabled = true;
			this->cmbGenero->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Masculino", L"Femenino" });
			this->cmbGenero->Location = System::Drawing::Point(190, 186);
			this->cmbGenero->Margin = System::Windows::Forms::Padding(5);
			this->cmbGenero->Name = L"cmbGenero";
			this->cmbGenero->Size = System::Drawing::Size(294, 37);
			this->cmbGenero->TabIndex = 5;
			// 
			// txtTelefono
			// 
			this->txtTelefono->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtTelefono->Location = System::Drawing::Point(839, 252);
			this->txtTelefono->Margin = System::Windows::Forms::Padding(5);
			this->txtTelefono->Name = L"txtTelefono";
			this->txtTelefono->Size = System::Drawing::Size(599, 34);
			this->txtTelefono->TabIndex = 8;
			// 
			// txtEdad
			// 
			this->txtEdad->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtEdad->Location = System::Drawing::Point(190, 121);
			this->txtEdad->Margin = System::Windows::Forms::Padding(5);
			this->txtEdad->Name = L"txtEdad";
			this->txtEdad->Size = System::Drawing::Size(294, 34);
			this->txtEdad->TabIndex = 3;
			// 
			// txtNombre
			// 
			this->txtNombre->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtNombre->Location = System::Drawing::Point(839, 59);
			this->txtNombre->Margin = System::Windows::Forms::Padding(5);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(599, 34);
			this->txtNombre->TabIndex = 2;
			// 
			// txtIdPersona
			// 
			this->txtIdPersona->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtIdPersona->Location = System::Drawing::Point(190, 57);
			this->txtIdPersona->Margin = System::Windows::Forms::Padding(5);
			this->txtIdPersona->Name = L"txtIdPersona";
			this->txtIdPersona->Size = System::Drawing::Size(294, 34);
			this->txtIdPersona->TabIndex = 1;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(569, 253);
			this->label7->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(134, 29);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Teléfonos :";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(13, 257);
			this->label6->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(141, 29);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Estado civil:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 186);
			this->label5->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(106, 29);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Género :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 121);
			this->label4->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(82, 29);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Edad :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(569, 62);
			this->label3->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(249, 29);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Nombres y Apellidos :";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 62);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"DNI :";
			// 
			// btnGrabar
			// 
			this->btnGrabar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnGrabar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGrabar->ForeColor = System::Drawing::Color::White;
			this->btnGrabar->Location = System::Drawing::Point(394, 716);
			this->btnGrabar->Margin = System::Windows::Forms::Padding(5);
			this->btnGrabar->Name = L"btnGrabar";
			this->btnGrabar->Size = System::Drawing::Size(306, 56);
			this->btnGrabar->TabIndex = 11;
			this->btnGrabar->Text = L"Grabar";
			this->btnGrabar->UseVisualStyleBackColor = false;
			this->btnGrabar->Click += gcnew System::EventHandler(this, &frmNuevoMedico::btnGrabar_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnCancelar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancelar->ForeColor = System::Drawing::Color::White;
			this->btnCancelar->Location = System::Drawing::Point(813, 716);
			this->btnCancelar->Margin = System::Windows::Forms::Padding(5);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(271, 56);
			this->btnCancelar->TabIndex = 12;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = false;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &frmNuevoMedico::btnCancelar_Click);
			// 
			// frmNuevoMedico
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1500, 795);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->btnGrabar);
			this->Controls->Add(this->btnCancelar);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"frmNuevoMedico";
			this->Text = L"Sistema Gestión Hospitalario - Médico - Nuevo registro";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &frmNuevoMedico::frmNuevoMedico_Load);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCertificaciones))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvEspecialidades))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmNuevoMedico_Load(System::Object^ sender, System::EventArgs^ e) {
		// Crear una nueva columna ComboBox
		DataGridViewComboBoxColumn^ comboBoxColumn = gcnew DataGridViewComboBoxColumn();
		comboBoxColumn->HeaderText = "Especialidad";
		comboBoxColumn->Name = "colEspecialidad";
		comboBoxColumn->Width = 350;
		//Listamos las Especialidades desde el archivo Especialidades.txt
		EspecialidadController^ especialidadController = gcnew EspecialidadController();
		List<Especialidad^>^ listaEspecialidades = especialidadController->listarEspecialidades();
		for each (Especialidad ^ objeto in listaEspecialidades) {
			comboBoxColumn->Items->Add(objeto->getNombre());
		}
		//O se puede listar directamente en duro:
		//comboBoxColumn->Items->AddRange(gcnew array<String^> { "Cardiología", "Cirugía General", "Dermatología", "Endocrinología", "Gastroenterología", "Geriatría", "Ginecología", "Medicina de Urgencias", "Medicina Interna", "Nefrología", "Neumología", "Neurología", "Oftalmología", "Oncología", "Ortopedia", "Otorrinolaringología", "Pediatría", "Psiquiatría", "Reumatología", "Urología" });
		this->dgvEspecialidades->Columns->Add(comboBoxColumn);
	}

	private: System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnGrabar_Click(System::Object^ sender, System::EventArgs^ e) {
		int idPersona = Convert::ToInt32(this->txtIdPersona->Text);
		String^ nombre = this->txtNombre->Text;
		int edad = Convert::ToInt32(this->txtEdad->Text);
		String^ direccion = this->txtDireccion->Text;
		String^ genero = this->cmbGenero->Text;
		String^ email = this->txtEmail->Text;
		String^ estadoCivil = this->cmbEstadoCivil->Text;
		String^ telefono = this->txtTelefono->Text;
		double altura = Convert::ToDouble(this->txtAltura->Text);
		int idMedico = Convert::ToInt32(this->txtIdMedico->Text);
		String^ numeroColegioMedico = this->txtNumeroColegioMedico->Text;

		//Lista de Certificaciones
		List<String^>^ certificaciones = gcnew List<String^>();
		if (this->dgvCertificaciones->Rows->Count > 0) {
			//No esta vacio
			for (int i = 0; i < dgvCertificaciones->Rows->Count; i++) {
				// Verificar si la fila no está vacía (por ejemplo, si no tiene celdas nulas)
				if (dgvCertificaciones->Rows[i]->Cells[0]->Value != nullptr) {
					String^ resultado = dgvCertificaciones->Rows[i]->Cells[0]->Value->ToString();
					certificaciones->Add(resultado);
				}
			}
		}

		//Lista de Especilidades
		EspecialidadController^ especialidadController = gcnew EspecialidadController();
		List<Especialidad^>^ especialidades = gcnew List<Especialidad^>();
		if (this->dgvEspecialidades->Rows->Count > 0) {
			//No esta vacio
			// Listar todas las especialidades registradas
			for (int i = 0; i < dgvEspecialidades->Rows->Count; i++) {
				// Verificar si la fila no está vacía (por ejemplo, si no tiene celdas nulas)
				if (dgvEspecialidades->Rows[i]->Cells[0]->Value != nullptr) {
					String^ sEspecialidad = dgvEspecialidades->Rows[i]->Cells[0]->Value->ToString();
					especialidades->Add(especialidadController->buscarEspecialidadByNombre(sEspecialidad));
				}
			}
		}

		List<int>^ idCitasAsignadas = gcnew List<int>();
		List<Paciente^>^ pacientesAsociados = gcnew List<Paciente^>();

		MedicoController^ objMedico = gcnew MedicoController();
		objMedico->agregarMedico(idPersona, nombre, edad, genero, direccion, telefono, email, estadoCivil, altura, idMedico, numeroColegioMedico, certificaciones, especialidades, idCitasAsignadas, pacientesAsociados);
		MessageBox::Show("La información del Médico se ha reistrado con éxito...!", "Grabación Exitosa",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
		this->Close();
	}
	
	};
}
