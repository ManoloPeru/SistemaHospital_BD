#pragma once
#include "frmNuevaEspecialidad.h"
#include "frmEditarEspecialidad.h"

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
	/// Resumen de frmMantEspecialidades
	/// </summary>
	public ref class frmMantEspecialidades : public System::Windows::Forms::Form
	{
	public:
		frmMantEspecialidades(void)
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
		~frmMantEspecialidades()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ btnBuscar;
	private: System::Windows::Forms::TextBox^ txtNombre;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dgvLista;

	private: System::Windows::Forms::Button^ btnNuevo;
	private: System::Windows::Forms::Button^ btnEditar;
	private: System::Windows::Forms::Button^ btnEliminar;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colNombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colDescripcion;














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
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dgvLista = (gcnew System::Windows::Forms::DataGridView());
			this->colId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colNombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colDescripcion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnNuevo = (gcnew System::Windows::Forms::Button());
			this->btnEditar = (gcnew System::Windows::Forms::Button());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btnBuscar);
			this->groupBox1->Controls->Add(this->txtNombre);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(21, 22);
			this->groupBox1->Margin = System::Windows::Forms::Padding(5);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(5);
			this->groupBox1->Size = System::Drawing::Size(1232, 116);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterios de Búsqueda";
			// 
			// btnBuscar
			// 
			this->btnBuscar->Location = System::Drawing::Point(467, 49);
			this->btnBuscar->Margin = System::Windows::Forms::Padding(5);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(131, 42);
			this->btnBuscar->TabIndex = 2;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = true;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &frmMantEspecialidades::btnBuscar_Click);
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(133, 57);
			this->txtNombre->Margin = System::Windows::Forms::Padding(5);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(293, 34);
			this->txtNombre->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 60);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(113, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nombre :";
			// 
			// dgvLista
			// 
			this->dgvLista->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvLista->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->colId, this->colNombre,
					this->colDescripcion
			});
			this->dgvLista->Location = System::Drawing::Point(21, 148);
			this->dgvLista->Margin = System::Windows::Forms::Padding(5);
			this->dgvLista->Name = L"dgvLista";
			this->dgvLista->RowHeadersWidth = 51;
			this->dgvLista->RowTemplate->Height = 24;
			this->dgvLista->Size = System::Drawing::Size(1232, 402);
			this->dgvLista->TabIndex = 1;
			// 
			// colId
			// 
			this->colId->HeaderText = L"Id";
			this->colId->MinimumWidth = 6;
			this->colId->Name = L"colId";
			this->colId->Width = 125;
			// 
			// colNombre
			// 
			this->colNombre->HeaderText = L"Nombre Especialidad";
			this->colNombre->MinimumWidth = 6;
			this->colNombre->Name = L"colNombre";
			this->colNombre->Width = 300;
			// 
			// colDescripcion
			// 
			this->colDescripcion->HeaderText = L"Descripción";
			this->colDescripcion->MinimumWidth = 6;
			this->colDescripcion->Name = L"colDescripcion";
			this->colDescripcion->Width = 750;
			// 
			// btnNuevo
			// 
			this->btnNuevo->Location = System::Drawing::Point(292, 584);
			this->btnNuevo->Margin = System::Windows::Forms::Padding(5);
			this->btnNuevo->Name = L"btnNuevo";
			this->btnNuevo->Size = System::Drawing::Size(131, 42);
			this->btnNuevo->TabIndex = 2;
			this->btnNuevo->Text = L"Nuevo";
			this->btnNuevo->UseVisualStyleBackColor = true;
			this->btnNuevo->Click += gcnew System::EventHandler(this, &frmMantEspecialidades::btnNuevo_Click);
			// 
			// btnEditar
			// 
			this->btnEditar->Location = System::Drawing::Point(518, 584);
			this->btnEditar->Margin = System::Windows::Forms::Padding(5);
			this->btnEditar->Name = L"btnEditar";
			this->btnEditar->Size = System::Drawing::Size(131, 42);
			this->btnEditar->TabIndex = 3;
			this->btnEditar->Text = L"Editar";
			this->btnEditar->UseVisualStyleBackColor = true;
			this->btnEditar->Click += gcnew System::EventHandler(this, &frmMantEspecialidades::btnEditar_Click);
			// 
			// btnEliminar
			// 
			this->btnEliminar->Location = System::Drawing::Point(726, 584);
			this->btnEliminar->Margin = System::Windows::Forms::Padding(5);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(131, 42);
			this->btnEliminar->TabIndex = 4;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = true;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &frmMantEspecialidades::btnEliminar_Click);
			// 
			// frmMantEspecialidades
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1274, 652);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnEditar);
			this->Controls->Add(this->btnNuevo);
			this->Controls->Add(this->dgvLista);
			this->Controls->Add(this->groupBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"frmMantEspecialidades";
			this->Text = L"Gestión de Especialidades";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &frmMantEspecialidades::frmMantEspecialidades_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmMantEspecialidades_Load(System::Object^ sender, System::EventArgs^ e) {
		// Aquí se ejecuta el método listarEspecialidades cuando se carga el formulario
		String^ pathArchivo = pathBin() + "especialidad.bin";

		EspecialidadController^ especialidadController = gcnew EspecialidadController();
		List<Especialidad^>^ listaEspecialidades = especialidadController->listarEspecialidadesBin(pathArchivo);

		mostrarGrilla(listaEspecialidades);
	}
	private: System::Void btnNuevo_Click(System::Object^ sender, System::EventArgs^ e) {
		frmNuevaEspecialidad^ ventanaNuevaEspecialidad = gcnew frmNuevaEspecialidad();
		ventanaNuevaEspecialidad->ShowDialog();
		this->dgvLista->Rows->Clear();
		String^ pathArchivo = pathBin() + "especialidad.bin";
		EspecialidadController^ especialidadController = gcnew EspecialidadController();
		List<Especialidad^>^ listaEspecialidades = especialidadController->listarEspecialidadesBin(pathArchivo);
		mostrarGrilla(listaEspecialidades);
	}
	private: System::Void btnEditar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Verificar si hay al menos una fila seleccionada
		if (dgvLista->SelectedRows->Count == 0) {
			MessageBox::Show("Por favor, seleccione una fila para editar el registro.", "Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return; // Salir del evento si no hay filas seleccionadas
		}
		String^ pathArchivo = pathBin() + "especialidad.bin";

		int filaSeleccionada = this->dgvLista->SelectedRows[0]->Index; /*Le pongo [0] porque deseo el índice de la única fila que he seleccionado*/
		int idEditar = Convert::ToInt32(this->dgvLista->Rows[filaSeleccionada]->Cells[0]->Value->ToString());
		EspecialidadController^ especialidadController = gcnew EspecialidadController();
		Especialidad^ objEspecialidad = especialidadController->buscarEspecialidadByIdBin(idEditar, pathArchivo);

		frmEditarEspecialidad^ ventanaEditarEspecialidad = gcnew frmEditarEspecialidad(objEspecialidad);
		ventanaEditarEspecialidad->ShowDialog();
		this->dgvLista->Rows->Clear();
		List<Especialidad^>^ listaEspecialidades = especialidadController->listarEspecialidadesBin(pathArchivo);
		mostrarGrilla(listaEspecialidades);
	}
	private: System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Verificar si hay al menos una fila seleccionada
		if (dgvLista->SelectedRows->Count == 0) {
			MessageBox::Show("Por favor, seleccione una fila para eliminar un registro.", "Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return; // Salir del evento si no hay filas seleccionadas
		}

		// Preguntar al usuario si está seguro de eliminar el registro
		System::Windows::Forms::DialogResult resultado = MessageBox::Show("¿Está seguro de que desea eliminar el registro seleccionado?",
			"Confirmación de eliminación", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

		// Si el usuario selecciona "No", cancelar la operación
		if (resultado == System::Windows::Forms::DialogResult::No) {
			return; // Salir del evento si el usuario cancela
		}

		String^ pathArchivo = pathBin() + "especialidad.bin";
		EspecialidadController^ especialidadController = gcnew EspecialidadController();
		for (int i = 0; i < this->dgvLista->SelectedRows->Count; i++) {
			int filaSeleccionada = this->dgvLista->SelectedRows[i]->Index;
			int idEliminar = Convert::ToInt32(this->dgvLista->Rows[filaSeleccionada]->Cells[0]->Value->ToString());
			especialidadController->eliminarEspecialidad(idEliminar, pathArchivo);
		}
		MessageBox::Show("La Especialidad ha sido eliminado con éxito");
		this->dgvLista->Rows->Clear();
		List<Especialidad^>^ listaEspecialidades = especialidadController->listarEspecialidadesBin(pathArchivo);
		mostrarGrilla(listaEspecialidades);
	}

	private: System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ nombre = this->txtNombre->Text;
		List<Especialidad^>^ listaEspecialidades;
		EspecialidadController^ objController = gcnew EspecialidadController();
		String^ pathArchivo = pathBin() + "especialidad.bin";
		if (nombre->CompareTo("") == 0) {
			listaEspecialidades = objController->listarEspecialidadesBin(pathArchivo);
		}
		else
		{
			listaEspecialidades = objController->buscarEspecialidadByNombreBin(nombre, pathArchivo);
		}
		mostrarGrilla(listaEspecialidades);
	}
		   /*METODOSPERSONALES*/
	public: void mostrarGrilla(List<Especialidad^>^ listaEspecialidades) {
		this->dgvLista->Rows->Clear();
		for (int i = 0; i < listaEspecialidades->Count; i++) {
			Especialidad^ especialidad = listaEspecialidades[i];
			array<String^>^ filaGrilla = gcnew array<String^>(3);
			filaGrilla[0] = Convert::ToString(especialidad->getIdEspecialidad());
			filaGrilla[1] = especialidad->getNombre();
			filaGrilla[2] = especialidad->getDescripcion();
			this->dgvLista->Rows->Add(filaGrilla);
		}
	}
	public: String^ pathBin() {
		// Obtiene la ruta de ejecución
		String^ rutaEjecucion = Application::StartupPath;
		// Navega hacia la carpeta padre dos niveles arriba para eliminar "x64\Debug"
		String^ rutaBase = Directory::GetParent(Directory::GetParent(rutaEjecucion)->FullName)->FullName;
		// Añade la subcarpeta "bin"
		String^ rutaFinal = Path::Combine(rutaBase, "binario\\");
		return rutaFinal;
	}



	};
}
