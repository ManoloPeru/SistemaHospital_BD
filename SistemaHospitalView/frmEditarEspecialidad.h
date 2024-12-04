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
	using namespace System::IO;

	/// <summary>
	/// Resumen de frmEditarEspecialidad
	/// </summary>
	public ref class frmEditarEspecialidad : public System::Windows::Forms::Form
	{
	public:
		frmEditarEspecialidad(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

		frmEditarEspecialidad(Especialidad^ objEspecialidad)
		{
			InitializeComponent();
			this->objEspecialidad = objEspecialidad;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmEditarEspecialidad()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnCancelar;
	protected:

	private: System::Windows::Forms::Button^ btnGrabar;
	protected:

	private: System::Windows::Forms::TextBox^ txtNombre;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtIdEspecialidad;

	private: System::Windows::Forms::Label^ label1;

		   /* Este atributo se crea porque el constructor está recibiendo un objeto del tipo Especialidad y
		   ese objeto hay que asignarselo a un atributo */
	private: Especialidad^ objEspecialidad;
	private: System::Windows::Forms::TextBox^ txtDescripcion;
	private: System::Windows::Forms::Label^ label3;

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
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->btnGrabar = (gcnew System::Windows::Forms::Button());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtIdEspecialidad = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtDescripcion = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnCancelar
			// 
			this->btnCancelar->Location = System::Drawing::Point(380, 388);
			this->btnCancelar->Margin = System::Windows::Forms::Padding(5);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(131, 42);
			this->btnCancelar->TabIndex = 11;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = true;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &frmEditarEspecialidad::btnCancelar_Click);
			// 
			// btnGrabar
			// 
			this->btnGrabar->Location = System::Drawing::Point(189, 388);
			this->btnGrabar->Margin = System::Windows::Forms::Padding(5);
			this->btnGrabar->Name = L"btnGrabar";
			this->btnGrabar->Size = System::Drawing::Size(131, 42);
			this->btnGrabar->TabIndex = 10;
			this->btnGrabar->Text = L"Grabar";
			this->btnGrabar->UseVisualStyleBackColor = true;
			this->btnGrabar->Click += gcnew System::EventHandler(this, &frmEditarEspecialidad::btnGrabar_Click);
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(189, 81);
			this->txtNombre->Margin = System::Windows::Forms::Padding(5);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(345, 34);
			this->txtNombre->TabIndex = 9;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(29, 84);
			this->label2->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(113, 29);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Nombre :";
			// 
			// txtIdEspecialidad
			// 
			this->txtIdEspecialidad->Enabled = false;
			this->txtIdEspecialidad->Location = System::Drawing::Point(189, 26);
			this->txtIdEspecialidad->Margin = System::Windows::Forms::Padding(5);
			this->txtIdEspecialidad->Name = L"txtIdEspecialidad";
			this->txtIdEspecialidad->Size = System::Drawing::Size(254, 34);
			this->txtIdEspecialidad->TabIndex = 7;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(29, 29);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(45, 29);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Id :";
			// 
			// txtDescripcion
			// 
			this->txtDescripcion->Location = System::Drawing::Point(189, 141);
			this->txtDescripcion->Multiline = true;
			this->txtDescripcion->Name = L"txtDescripcion";
			this->txtDescripcion->Size = System::Drawing::Size(536, 185);
			this->txtDescripcion->TabIndex = 13;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(33, 146);
			this->label3->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(153, 29);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Descripción :";
			// 
			// frmEditarEspecialidad
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(768, 464);
			this->Controls->Add(this->txtDescripcion);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->btnGrabar);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtIdEspecialidad);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"frmEditarEspecialidad";
			this->Text = L"Editar Especialidad";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &frmEditarEspecialidad::frmEditarEspecialidad_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmEditarEspecialidad_Load(System::Object^ sender, System::EventArgs^ e) {
		this->txtIdEspecialidad->Text = Convert::ToString(this->objEspecialidad->getIdEspecialidad());
		this->txtNombre->Text = this->objEspecialidad->getNombre();
		this->txtDescripcion->Text = this->objEspecialidad->getDescripcion();


	}

	private: System::Void btnGrabar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ pathArchivo = pathBin() + "especialidad.bin";
		int idEspecialidad = Convert::ToInt32(this->txtIdEspecialidad->Text);
		String^ nombre = this->txtNombre->Text;
		String^ descripcion = this->txtDescripcion->Text;

		EspecialidadController^ objEspecialidad = gcnew EspecialidadController();
		objEspecialidad->modificarEspecialidad(idEspecialidad, nombre, descripcion, pathArchivo);
		MessageBox::Show("La información de la Especilidad se ha modificado con éxito...!", "Grabación Exitosa",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
		this->Close();
	}
	private: System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

		   /*METODOSPERSONALES*/
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
