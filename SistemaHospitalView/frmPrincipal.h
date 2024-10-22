#pragma once
#include "frmMantMedicos.h"

namespace SistemaHospitalView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmPrincipal
	/// </summary>
	public ref class frmPrincipal : public System::Windows::Forms::Form
	{
	public:
		frmPrincipal(void)
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
		~frmPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ mantenimientoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ medicoToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ transaccionesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ reportesToolStripMenuItem;

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->mantenimientoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->medicoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->transaccionesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->reportesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->mantenimientoToolStripMenuItem,
					this->transaccionesToolStripMenuItem, this->reportesToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(14, 4, 0, 4);
			this->menuStrip1->Size = System::Drawing::Size(2582, 44);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menStripPrincipal";
			// 
			// mantenimientoToolStripMenuItem
			// 
			this->mantenimientoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->medicoToolStripMenuItem });
			this->mantenimientoToolStripMenuItem->Name = L"mantenimientoToolStripMenuItem";
			this->mantenimientoToolStripMenuItem->Size = System::Drawing::Size(193, 36);
			this->mantenimientoToolStripMenuItem->Text = L"Mantenimiento";
			// 
			// medicoToolStripMenuItem
			// 
			this->medicoToolStripMenuItem->Name = L"medicoToolStripMenuItem";
			this->medicoToolStripMenuItem->Size = System::Drawing::Size(182, 36);
			this->medicoToolStripMenuItem->Text = L"Médico";
			this->medicoToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::medicoToolStripMenuItem_Click);
			// 
			// transaccionesToolStripMenuItem
			// 
			this->transaccionesToolStripMenuItem->Name = L"transaccionesToolStripMenuItem";
			this->transaccionesToolStripMenuItem->Size = System::Drawing::Size(174, 36);
			this->transaccionesToolStripMenuItem->Text = L"Transacciones";
			// 
			// reportesToolStripMenuItem
			// 
			this->reportesToolStripMenuItem->Name = L"reportesToolStripMenuItem";
			this->reportesToolStripMenuItem->Size = System::Drawing::Size(121, 36);
			this->reportesToolStripMenuItem->Text = L"Reportes";
			// 
			// frmPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2582, 1217);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"frmPrincipal";
			this->Text = L"Bienvenido al Sistema de Gestión de un Hospital Inteligente";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void medicoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		frmMantMedicos^ ventanaMedicos = gcnew frmMantMedicos();
		ventanaMedicos->MdiParent = this;
		ventanaMedicos->Show();
	}
};
}
