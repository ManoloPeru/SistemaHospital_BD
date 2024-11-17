#pragma once
#include "frmPrincipal.h" 

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
	/// Resumen de frmLogin
	/// </summary>
	public ref class frmLogin : public System::Windows::Forms::Form
	{
	public:
		frmLogin(void)
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
		~frmLogin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::TextBox^ txtContrasenia;
	private: System::Windows::Forms::TextBox^ txtUsuario;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnIngresar;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnIngresar = (gcnew System::Windows::Forms::Button());
			this->txtContrasenia = (gcnew System::Windows::Forms::TextBox());
			this->txtUsuario = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btnIngresar);
			this->groupBox1->Controls->Add(this->txtContrasenia);
			this->groupBox1->Controls->Add(this->txtUsuario);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(14, 24);
			this->groupBox1->Margin = System::Windows::Forms::Padding(5);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(5);
			this->groupBox1->Size = System::Drawing::Size(516, 282);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Información de acceso:";
			// 
			// btnIngresar
			// 
			this->btnIngresar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnIngresar->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnIngresar->Location = System::Drawing::Point(207, 192);
			this->btnIngresar->Name = L"btnIngresar";
			this->btnIngresar->Size = System::Drawing::Size(162, 48);
			this->btnIngresar->TabIndex = 4;
			this->btnIngresar->Text = L"Ingresar";
			this->btnIngresar->UseVisualStyleBackColor = false;
			this->btnIngresar->Click += gcnew System::EventHandler(this, &frmLogin::btnIngresar_Click);
			// 
			// txtContrasenia
			// 
			this->txtContrasenia->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtContrasenia->Location = System::Drawing::Point(207, 127);
			this->txtContrasenia->Name = L"txtContrasenia";
			this->txtContrasenia->PasswordChar = '*';
			this->txtContrasenia->Size = System::Drawing::Size(262, 34);
			this->txtContrasenia->TabIndex = 3;
			this->txtContrasenia->Text = L"admin";
			// 
			// txtUsuario
			// 
			this->txtUsuario->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtUsuario->Location = System::Drawing::Point(207, 65);
			this->txtUsuario->Name = L"txtUsuario";
			this->txtUsuario->Size = System::Drawing::Size(262, 34);
			this->txtUsuario->TabIndex = 2;
			this->txtUsuario->Text = L"admin";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(23, 130);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(142, 29);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Contraseña:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(23, 70);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(102, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Usuario:";
			// 
			// frmLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(546, 329);
			this->Controls->Add(this->groupBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"frmLogin";
			this->Text = L"Sistema Gestión Hospitalario - Autentificación";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnIngresar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ usuario = this->txtUsuario->Text;
		String^ contrasenia = this->txtContrasenia->Text;

		if (usuario->Equals("") || contrasenia->Equals(""))
		{
			MessageBox::Show("Las credenciales Usuario y/o Cotraseña no debe estar en blanco...!", "Error de credenciales",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else
		{
			PersonaController^ objController = gcnew PersonaController();
			Persona^ objPersona = objController->buscarPersonaByUsuario(usuario, contrasenia);
			if (objPersona != nullptr)
			{
				frmPrincipal^ ventanaPrincipal = gcnew frmPrincipal(objPersona);
				ventanaPrincipal->ShowDialog();
				this->Close();
			}
			else
			{
				MessageBox::Show("Las credenciales no son validas...!", "Error de credenciales",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
};
}
