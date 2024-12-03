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
	/// Resumen de frmBuscarMedico
	/// </summary>
	public ref class frmBuscarMedico : public System::Windows::Forms::Form
	{
	public:
		frmBuscarMedico(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

		frmBuscarMedico(Medico^ objMedico)
		{
			InitializeComponent();
			this->objMedico = objMedico;
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmBuscarMedico()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnSeleccionar;
	protected:

	private: System::Windows::Forms::DataGridView^ dgvLista;
	protected:





	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ btnBuscar;

	private: System::Windows::Forms::TextBox^ txtApellido;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;

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
			this->btnSeleccionar = (gcnew System::Windows::Forms::Button());
			this->dgvLista = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->txtApellido = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnSeleccionar
			// 
			this->btnSeleccionar->Location = System::Drawing::Point(380, 620);
			this->btnSeleccionar->Margin = System::Windows::Forms::Padding(5);
			this->btnSeleccionar->Name = L"btnSeleccionar";
			this->btnSeleccionar->Size = System::Drawing::Size(254, 66);
			this->btnSeleccionar->TabIndex = 5;
			this->btnSeleccionar->Text = L"Seleccionar";
			this->btnSeleccionar->UseVisualStyleBackColor = true;
			this->btnSeleccionar->Click += gcnew System::EventHandler(this, &frmBuscarMedico::btnSeleccionar_Click);
			// 
			// dgvLista
			// 
			this->dgvLista->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvLista->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column1, this->Column2,
					this->Column3, this->Column4
			});
			this->dgvLista->Location = System::Drawing::Point(14, 159);
			this->dgvLista->Margin = System::Windows::Forms::Padding(5);
			this->dgvLista->Name = L"dgvLista";
			this->dgvLista->RowHeadersWidth = 51;
			this->dgvLista->RowTemplate->Height = 24;
			this->dgvLista->Size = System::Drawing::Size(984, 451);
			this->dgvLista->TabIndex = 4;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Código";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Width = 125;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Apellidos";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->Width = 250;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Nombres";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 250;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Email";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->Width = 300;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btnBuscar);
			this->groupBox1->Controls->Add(this->txtApellido);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(14, 14);
			this->groupBox1->Margin = System::Windows::Forms::Padding(5);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(5);
			this->groupBox1->Size = System::Drawing::Size(984, 121);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterios de Búsqueda";
			// 
			// btnBuscar
			// 
			this->btnBuscar->Location = System::Drawing::Point(684, 49);
			this->btnBuscar->Margin = System::Windows::Forms::Padding(5);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(164, 53);
			this->btnBuscar->TabIndex = 2;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = true;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &frmBuscarMedico::btnBuscar_Click);
			// 
			// txtApellido
			// 
			this->txtApellido->Location = System::Drawing::Point(173, 58);
			this->txtApellido->Margin = System::Windows::Forms::Padding(5);
			this->txtApellido->Name = L"txtApellido";
			this->txtApellido->Size = System::Drawing::Size(481, 34);
			this->txtApellido->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(19, 61);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(126, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Apellidos :";
			// 
			// frmBuscarMedico
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1038, 716);
			this->Controls->Add(this->btnSeleccionar);
			this->Controls->Add(this->dgvLista);
			this->Controls->Add(this->groupBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"frmBuscarMedico";
			this->Text = L"frmBuscarMedico";
			this->Load += gcnew System::EventHandler(this, &frmBuscarMedico::frmBuscarMedico_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmBuscarMedico_Load(System::Object^ sender, System::EventArgs^ e) {
		// Aquí se ejecuta el método listarMedico cuando se carga el formulario
		MedicoController^ medicoController = gcnew MedicoController();
		List<Medico^>^ listaMedicos = medicoController->selectMedicos();

		mostrarGrilla(listaMedicos);
	}

	public: void mostrarGrilla(List<Medico^>^ listaMedicos) {
		this->dgvLista->Rows->Clear();
		for (int i = 0; i < listaMedicos->Count; i++) {
			Medico^ medico = listaMedicos[i];
			array<String^>^ filaGrilla = gcnew array<String^>(4);
			filaGrilla[0] = Convert::ToString(medico->getIdMedico());
			filaGrilla[1] = medico->getApellidos();
			filaGrilla[2] = medico->getNombres();
			filaGrilla[3] = medico->getEmail();
			this->dgvLista->Rows->Add(filaGrilla);
		}
	}

	private: System::Void btnSeleccionar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Verificar si hay al menos una fila seleccionada
		if (dgvLista->SelectedRows->Count == 0) {
			MessageBox::Show("Por favor, seleccione un registro.", "Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return; // Salir del evento si no hay filas seleccionadas
		}
		MedicoController^ medicoController = gcnew MedicoController();
		for (int i = 0; i < this->dgvLista->SelectedRows->Count; i++) {
			int filaSeleccionada = this->dgvLista->SelectedRows[i]->Index;
			int idSeleccionado = Convert::ToInt32(this->dgvLista->Rows[filaSeleccionada]->Cells[0]->Value->ToString());
			String^ apellidos = this->dgvLista->Rows[filaSeleccionada]->Cells[1]->Value->ToString();
			String^ nombres = this->dgvLista->Rows[filaSeleccionada]->Cells[2]->Value->ToString();
			this->objMedico->setIdMedico(idSeleccionado);
			this->objMedico->setApellidos(apellidos + " " + nombres);
			this->Close();
		}
	}
	private: System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ apellido = txtApellido->Text;
		MedicoController^ medicoController = gcnew MedicoController();
		List<Medico^>^ listaMedicos = medicoController->selectMedicosByApellido(apellido);
		mostrarGrilla(listaMedicos);
	}
	};
}
