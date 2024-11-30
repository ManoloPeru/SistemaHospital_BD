#pragma once
#include "frmNuevoEquipoMedico.h"
#include "frmEditarEquipoMedico.h"

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
	/// Resumen de frmMantEquiposMedicos
	/// </summary>
	public ref class frmMantEquiposMedicos : public System::Windows::Forms::Form
	{
	public:
		frmMantEquiposMedicos(void)
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
		~frmMantEquiposMedicos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ btnBuscar;
	protected:

	private: System::Windows::Forms::TextBox^ txtNombre;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;



	private: System::Windows::Forms::Button^ btnNuevo;
	private: System::Windows::Forms::Button^ btnEditar;
	private: System::Windows::Forms::Button^ btnEliminar;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ColNombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colDisonibilidad;




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
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->colId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColNombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colDisonibilidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnNuevo = (gcnew System::Windows::Forms::Button());
			this->btnEditar = (gcnew System::Windows::Forms::Button());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btnBuscar);
			this->groupBox1->Controls->Add(this->txtNombre);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(14, 23);
			this->groupBox1->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->groupBox1->Size = System::Drawing::Size(990, 126);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterios de Búsqueda";
			// 
			// btnBuscar
			// 
			this->btnBuscar->Location = System::Drawing::Point(834, 48);
			this->btnBuscar->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(131, 42);
			this->btnBuscar->TabIndex = 2;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = true;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &frmMantEquiposMedicos::btnBuscar_Click);
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(188, 56);
			this->txtNombre->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(457, 34);
			this->txtNombre->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 61);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(113, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nombre :";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->colId,
					this->ColNombre, this->colDisonibilidad
			});
			this->dataGridView1->Location = System::Drawing::Point(14, 157);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(990, 357);
			this->dataGridView1->TabIndex = 1;
			// 
			// colId
			// 
			this->colId->HeaderText = L"Código";
			this->colId->MinimumWidth = 6;
			this->colId->Name = L"colId";
			this->colId->Width = 125;
			// 
			// ColNombre
			// 
			this->ColNombre->HeaderText = L"Nombre";
			this->ColNombre->MinimumWidth = 6;
			this->ColNombre->Name = L"ColNombre";
			this->ColNombre->Width = 300;
			// 
			// colDisonibilidad
			// 
			this->colDisonibilidad->HeaderText = L"Disponibilidad";
			this->colDisonibilidad->MinimumWidth = 6;
			this->colDisonibilidad->Name = L"colDisonibilidad";
			this->colDisonibilidad->Width = 250;
			// 
			// btnNuevo
			// 
			this->btnNuevo->Location = System::Drawing::Point(241, 537);
			this->btnNuevo->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->btnNuevo->Name = L"btnNuevo";
			this->btnNuevo->Size = System::Drawing::Size(131, 42);
			this->btnNuevo->TabIndex = 2;
			this->btnNuevo->Text = L"Nuevo";
			this->btnNuevo->UseVisualStyleBackColor = true;
			this->btnNuevo->Click += gcnew System::EventHandler(this, &frmMantEquiposMedicos::btnNuevo_Click);
			// 
			// btnEditar
			// 
			this->btnEditar->Location = System::Drawing::Point(441, 537);
			this->btnEditar->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->btnEditar->Name = L"btnEditar";
			this->btnEditar->Size = System::Drawing::Size(131, 42);
			this->btnEditar->TabIndex = 3;
			this->btnEditar->Text = L"Editar";
			this->btnEditar->UseVisualStyleBackColor = true;
			this->btnEditar->Click += gcnew System::EventHandler(this, &frmMantEquiposMedicos::btnEditar_Click);
			// 
			// btnEliminar
			// 
			this->btnEliminar->Location = System::Drawing::Point(640, 537);
			this->btnEliminar->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(131, 42);
			this->btnEliminar->TabIndex = 4;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = true;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &frmMantEquiposMedicos::btnEliminar_Click);
			// 
			// frmMantEquiposMedicos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1044, 614);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnEditar);
			this->Controls->Add(this->btnNuevo);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->Name = L"frmMantEquiposMedicos";
			this->Text = L"Gestión de Equipos Médicos";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e) {

		EquipoMedicoController^ equipoController = gcnew EquipoMedicoController();
		List<EquipoMedico^>^ listaEquipos = gcnew List<EquipoMedico^>();
		String^ nombre = this->txtNombre->Text;
		if (nombre->Length > 0) {
			listaEquipos = equipoController->listarEquiposMedicosxNombre(nombre);
		}
		else
		{
			listaEquipos = equipoController->listarEquiposMedicosAll();
		}
		mostrarGrilla(listaEquipos);
	}


	public: void mostrarGrilla(List<EquipoMedico^>^ listaEquipos) {
		this->dataGridView1->Rows->Clear();
		for (int i = 0; i < listaEquipos->Count; i++) {
			EquipoMedico^ equipo = listaEquipos[i];
			array<String^>^ filaGrilla = gcnew array<String^>(3);
			filaGrilla[0] = Convert::ToString(equipo->getIdEquipo());
			filaGrilla[1] = equipo->getNombre();
			filaGrilla[2] = equipo->getDisponibilidad();

			this->dataGridView1->Rows->Add(filaGrilla);
		}
	}

	private: System::Void btnNuevo_Click(System::Object^ sender, System::EventArgs^ e) {

		frmNuevoEquipoMedico^ ventanaNuevoProfesor = gcnew frmNuevoEquipoMedico();
		ventanaNuevoProfesor->ShowDialog();
		EquipoMedicoController^ equipoController = gcnew EquipoMedicoController();
		List<EquipoMedico^>^ listaEquipos = equipoController->listarEquiposMedicosAll();
		mostrarGrilla(listaEquipos);
	}
	private: System::Void btnEditar_Click(System::Object^ sender, System::EventArgs^ e) {
		int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
		int idEditar = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value->ToString());
		EquipoMedicoController^ equipoController = gcnew EquipoMedicoController();
		EquipoMedico^ equipo = equipoController->buscarEquipoMedicoById(idEditar);

		frmEditarEquipoMedico^ ventanaEditarEquipo = gcnew frmEditarEquipoMedico(equipo);
		ventanaEditarEquipo->ShowDialog();
		/*Vuelvo a cargar todos con el equipo que acabo de editar*/
		List<EquipoMedico^>^ listaEquipos = equipoController->listarEquiposMedicosAll();
		mostrarGrilla(listaEquipos);
	}
	private: System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {

		int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
		int idEliminar = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value->ToString());
		EquipoMedicoController^ equipoController = gcnew EquipoMedicoController();
		equipoController->eliminarEquipoMedico(idEliminar);
		MessageBox::Show("El equipoMedico se ha eliminado con éxito");
		/*Vuelvo a cargar todos sin el equipo que acabo de eliminar*/
		List<EquipoMedico^>^ listaEquipos = equipoController->listarEquiposMedicosAll();
		mostrarGrilla(listaEquipos);
	}
	};
}
