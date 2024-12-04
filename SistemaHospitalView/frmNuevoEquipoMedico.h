#pragma once

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
	/// Resumen de frmNuevoEquipoMedico
	/// </summary>
	public ref class frmNuevoEquipoMedico : public System::Windows::Forms::Form
	{
	public:
		frmNuevoEquipoMedico(void)
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
		~frmNuevoEquipoMedico()
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
	private: System::Windows::Forms::TextBox^ txtId;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::ComboBox^ cmbDisponibilidad;
	private: System::Windows::Forms::Button^ btnGrabar;
	private: System::Windows::Forms::Button^ btnCancelar;






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
			this->txtId = (gcnew System::Windows::Forms::TextBox());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->cmbDisponibilidad = (gcnew System::Windows::Forms::ComboBox());
			this->btnGrabar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(41, 46);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(45, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Id :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(41, 99);
			this->label2->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(113, 29);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Nombre :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(41, 155);
			this->label3->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(180, 29);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Disponibilidad :";
			// 
			// txtId
			// 
			this->txtId->Enabled = false;
			this->txtId->Location = System::Drawing::Point(284, 39);
			this->txtId->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->txtId->Name = L"txtId";
			this->txtId->Size = System::Drawing::Size(488, 34);
			this->txtId->TabIndex = 3;
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(284, 92);
			this->txtNombre->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(488, 34);
			this->txtNombre->TabIndex = 4;
			// 
			// cmbDisponibilidad
			// 
			this->cmbDisponibilidad->FormattingEnabled = true;
			this->cmbDisponibilidad->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Disponible", L"No Disponible" });
			this->cmbDisponibilidad->Location = System::Drawing::Point(284, 155);
			this->cmbDisponibilidad->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->cmbDisponibilidad->Name = L"cmbDisponibilidad";
			this->cmbDisponibilidad->Size = System::Drawing::Size(390, 37);
			this->cmbDisponibilidad->TabIndex = 5;
			// 
			// btnGrabar
			// 
			this->btnGrabar->Location = System::Drawing::Point(209, 293);
			this->btnGrabar->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->btnGrabar->Name = L"btnGrabar";
			this->btnGrabar->Size = System::Drawing::Size(164, 53);
			this->btnGrabar->TabIndex = 6;
			this->btnGrabar->Text = L"Grabar";
			this->btnGrabar->UseVisualStyleBackColor = true;
			this->btnGrabar->Click += gcnew System::EventHandler(this, &frmNuevoEquipoMedico::btnGrabar_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->Location = System::Drawing::Point(429, 293);
			this->btnCancelar->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(164, 53);
			this->btnCancelar->TabIndex = 7;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = true;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &frmNuevoEquipoMedico::btnCancelar_Click);
			// 
			// frmNuevoEquipoMedico
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(832, 395);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->btnGrabar);
			this->Controls->Add(this->cmbDisponibilidad);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->txtId);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->Name = L"frmNuevoEquipoMedico";
			this->Text = L"Nuevo Equipo Médico";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnGrabar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ nombre = this->txtNombre->Text;
		String^ disponibilidad = this->cmbDisponibilidad->Text;
		bool bInsertar = true;
		EquipoMedicoController^ equipoController = gcnew EquipoMedicoController();
		List<EquipoMedico^>^ listaEquipos = equipoController->listarEquiposMedicosAll();
		if (listaEquipos->Count > 0)
		{
			EquipoMedico^ especialidadEncontrado = gcnew EquipoMedico();
			for each (EquipoMedico ^ especialidad in listaEquipos) {
				if (especialidad->getNombre()->ToUpper()->Equals(nombre->ToUpper())) {
					// Verificar por ID de especialidad
					MessageBox::Show("El equipo médico ya se encuentra registrado");
					bInsertar = false;
					break;
				}
			}
		}
		if (bInsertar)
		{
			equipoController->registrarEquipoMedico(nombre, disponibilidad);
			MessageBox::Show("El equipoMedico se ha registrado con éxito");
		}
		this->Close();
	}

	private: System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
