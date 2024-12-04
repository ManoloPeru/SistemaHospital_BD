#pragma once
#include "frmRegistrarCita.h"

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
	/// Resumen de frmMantCitas
	/// </summary>
	public ref class frmMantCitas : public System::Windows::Forms::Form
	{
	public:
		frmMantCitas(void)
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
		~frmMantCitas()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ btnBuscar;

	private: System::Windows::Forms::DateTimePicker^ dtpFecha;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dgvLista;





	private: System::Windows::Forms::Button^ btnAgregar;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;

	protected:

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
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->dtpFecha = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dgvLista = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnAgregar = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btnBuscar);
			this->groupBox1->Controls->Add(this->dtpFecha);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(26, 28);
			this->groupBox1->Margin = System::Windows::Forms::Padding(5);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(5);
			this->groupBox1->Size = System::Drawing::Size(1223, 119);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterio de Búsqueda";
			// 
			// btnBuscar
			// 
			this->btnBuscar->Location = System::Drawing::Point(394, 43);
			this->btnBuscar->Margin = System::Windows::Forms::Padding(5);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(164, 53);
			this->btnBuscar->TabIndex = 2;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = true;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &frmMantCitas::btnBuscar_Click);
			// 
			// dtpFecha
			// 
			this->dtpFecha->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpFecha->Location = System::Drawing::Point(188, 50);
			this->dtpFecha->Margin = System::Windows::Forms::Padding(5);
			this->dtpFecha->Name = L"dtpFecha";
			this->dtpFecha->Size = System::Drawing::Size(169, 34);
			this->dtpFecha->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(30, 55);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Fecha :";
			// 
			// dgvLista
			// 
			this->dgvLista->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvLista->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column1, this->Column2,
					this->Column3, this->Column4
			});
			this->dgvLista->Location = System::Drawing::Point(26, 157);
			this->dgvLista->Margin = System::Windows::Forms::Padding(5);
			this->dgvLista->Name = L"dgvLista";
			this->dgvLista->RowHeadersWidth = 51;
			this->dgvLista->RowTemplate->Height = 24;
			this->dgvLista->Size = System::Drawing::Size(1223, 388);
			this->dgvLista->TabIndex = 1;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Código Cita";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Width = 200;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Nombre Paciente";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->Width = 350;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Nombre Médico";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 350;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Hora";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->Width = 125;
			// 
			// btnAgregar
			// 
			this->btnAgregar->Location = System::Drawing::Point(542, 555);
			this->btnAgregar->Margin = System::Windows::Forms::Padding(5);
			this->btnAgregar->Name = L"btnAgregar";
			this->btnAgregar->Size = System::Drawing::Size(188, 66);
			this->btnAgregar->TabIndex = 2;
			this->btnAgregar->Text = L"Agregar";
			this->btnAgregar->UseVisualStyleBackColor = true;
			this->btnAgregar->Click += gcnew System::EventHandler(this, &frmMantCitas::btnAgregar_Click);
			// 
			// frmMantCitas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1296, 643);
			this->Controls->Add(this->btnAgregar);
			this->Controls->Add(this->dgvLista);
			this->Controls->Add(this->groupBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"frmMantCitas";
			this->Text = L"Mantenimiento de Citas";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &frmMantCitas::frmMantCitas_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	public: void mostrarGrilla(List<Cita^>^ listaCitas) {
		this->dgvLista->Rows->Clear();
		for (int i = 0; i < listaCitas->Count; i++) {
			Cita^ cita = listaCitas[i];
			array<String^>^ filaGrilla = gcnew array<String^>(4);
			filaGrilla[0] = Convert::ToString(cita->getIdCita());
			filaGrilla[1] = cita->getNombrePaciente();
			filaGrilla[2] = cita->getNombreMedico();
			filaGrilla[3] = cita->getHora();
			this->dgvLista->Rows->Add(filaGrilla);
		}
	}

	private: System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Aquí se ejecuta el método listarMedico cuando se carga el formulario
		CitaController^ citaController = gcnew CitaController();
		List<Cita^>^ listaCitas = citaController->selectCita(dtpFecha->Text);
		mostrarGrilla(listaCitas);
	}
	private: System::Void btnAgregar_Click(System::Object^ sender, System::EventArgs^ e) {
		frmRegistrarCita^ ventanaRegistrarCita = gcnew frmRegistrarCita();
		ventanaRegistrarCita->ShowDialog();
		CitaController^ citaController = gcnew CitaController();
		List<Cita^>^ listaCitas = citaController->selectCita(dtpFecha->Text);
		mostrarGrilla(listaCitas);
	}
	private: System::Void frmMantCitas_Load(System::Object^ sender, System::EventArgs^ e) {
		// Aquí se ejecuta el método listarMedico cuando se carga el formulario
		CitaController^ citaController = gcnew CitaController();
		List<Cita^>^ listaCitas = citaController->selectCita(dtpFecha->Text);
		mostrarGrilla(listaCitas);
	}
};
}
