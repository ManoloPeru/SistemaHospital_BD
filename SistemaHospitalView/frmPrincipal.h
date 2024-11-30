#pragma once
#include "frmMantMedicos.h"
#include "frmVerCitas.h"
#include "frmMantEspecialidades.h"
#include "frmReporteEquiposMedicos.h"
#include "frmMantEquiposMedicos.h"

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
		frmPrincipal(Persona^ objPersona)
		{
			InitializeComponent();
			this->objPersona = objPersona;
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
	private: System::Windows::Forms::ToolStripMenuItem^ verCitaMédicaToolStripMenuItem;
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^ tssLblFechaHora;
	private: System::Windows::Forms::ToolStripStatusLabel^ tssLblUsuario;

		   /* Este atributo se crea porque el constructor está recibiendo un objeto del tipo Medico y
		  ese objeto hay que asignarselo a un atributo */
	private: Persona^ objPersona;
	private: System::Windows::Forms::ToolStripMenuItem^ gestiónDeEspecialidadesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ equiposMédicosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ equiposMédicosToolStripMenuItem1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmPrincipal::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->mantenimientoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->medicoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gestiónDeEspecialidadesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->transaccionesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->verCitaMédicaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->reportesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->equiposMédicosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->tssLblFechaHora = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->tssLblUsuario = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->equiposMédicosToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
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
			this->menuStrip1->Size = System::Drawing::Size(2582, 92);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menStripPrincipal";
			// 
			// mantenimientoToolStripMenuItem
			// 
			this->mantenimientoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->medicoToolStripMenuItem,
					this->gestiónDeEspecialidadesToolStripMenuItem, this->equiposMédicosToolStripMenuItem1
			});
			this->mantenimientoToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mantenimientoToolStripMenuItem.Image")));
			this->mantenimientoToolStripMenuItem->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->mantenimientoToolStripMenuItem->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->mantenimientoToolStripMenuItem->Name = L"mantenimientoToolStripMenuItem";
			this->mantenimientoToolStripMenuItem->Size = System::Drawing::Size(193, 84);
			this->mantenimientoToolStripMenuItem->Text = L"Mantenimiento";
			this->mantenimientoToolStripMenuItem->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			// 
			// medicoToolStripMenuItem
			// 
			this->medicoToolStripMenuItem->Name = L"medicoToolStripMenuItem";
			this->medicoToolStripMenuItem->Size = System::Drawing::Size(378, 36);
			this->medicoToolStripMenuItem->Text = L"Médico";
			this->medicoToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::medicoToolStripMenuItem_Click);
			// 
			// gestiónDeEspecialidadesToolStripMenuItem
			// 
			this->gestiónDeEspecialidadesToolStripMenuItem->Name = L"gestiónDeEspecialidadesToolStripMenuItem";
			this->gestiónDeEspecialidadesToolStripMenuItem->Size = System::Drawing::Size(378, 36);
			this->gestiónDeEspecialidadesToolStripMenuItem->Text = L"Gestión de especialidades";
			this->gestiónDeEspecialidadesToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::gestiónDeEspecialidadesToolStripMenuItem_Click);
			// 
			// transaccionesToolStripMenuItem
			// 
			this->transaccionesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->verCitaMédicaToolStripMenuItem });
			this->transaccionesToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"transaccionesToolStripMenuItem.Image")));
			this->transaccionesToolStripMenuItem->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->transaccionesToolStripMenuItem->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->transaccionesToolStripMenuItem->Name = L"transaccionesToolStripMenuItem";
			this->transaccionesToolStripMenuItem->Size = System::Drawing::Size(79, 84);
			this->transaccionesToolStripMenuItem->Text = L"Citas";
			this->transaccionesToolStripMenuItem->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			// 
			// verCitaMédicaToolStripMenuItem
			// 
			this->verCitaMédicaToolStripMenuItem->Name = L"verCitaMédicaToolStripMenuItem";
			this->verCitaMédicaToolStripMenuItem->Size = System::Drawing::Size(269, 36);
			this->verCitaMédicaToolStripMenuItem->Text = L"Ver Cita Médica";
			this->verCitaMédicaToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::verCitaMédicaToolStripMenuItem_Click);
			// 
			// reportesToolStripMenuItem
			// 
			this->reportesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->equiposMédicosToolStripMenuItem });
			this->reportesToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"reportesToolStripMenuItem.Image")));
			this->reportesToolStripMenuItem->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->reportesToolStripMenuItem->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->reportesToolStripMenuItem->Name = L"reportesToolStripMenuItem";
			this->reportesToolStripMenuItem->Size = System::Drawing::Size(121, 84);
			this->reportesToolStripMenuItem->Text = L"Reportes";
			this->reportesToolStripMenuItem->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			// 
			// equiposMédicosToolStripMenuItem
			// 
			this->equiposMédicosToolStripMenuItem->Name = L"equiposMédicosToolStripMenuItem";
			this->equiposMédicosToolStripMenuItem->Size = System::Drawing::Size(282, 36);
			this->equiposMédicosToolStripMenuItem->Text = L"Equipos médicos";
			this->equiposMédicosToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::equiposMédicosToolStripMenuItem_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->tssLblFechaHora,
					this->tssLblUsuario
			});
			this->statusStrip1->Location = System::Drawing::Point(0, 1029);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(2582, 26);
			this->statusStrip1->TabIndex = 3;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// tssLblFechaHora
			// 
			this->tssLblFechaHora->Name = L"tssLblFechaHora";
			this->tssLblFechaHora->Size = System::Drawing::Size(117, 20);
			this->tssLblFechaHora->Text = L"tssLblFechaHora";
			// 
			// tssLblUsuario
			// 
			this->tssLblUsuario->Name = L"tssLblUsuario";
			this->tssLblUsuario->Size = System::Drawing::Size(2450, 20);
			this->tssLblUsuario->Spring = true;
			this->tssLblUsuario->Text = L"tssLblUsuario";
			// 
			// equiposMédicosToolStripMenuItem1
			// 
			this->equiposMédicosToolStripMenuItem1->Name = L"equiposMédicosToolStripMenuItem1";
			this->equiposMédicosToolStripMenuItem1->Size = System::Drawing::Size(378, 36);
			this->equiposMédicosToolStripMenuItem1->Text = L"Equipos médicos";
			this->equiposMédicosToolStripMenuItem1->Click += gcnew System::EventHandler(this, &frmPrincipal::equiposMédicosToolStripMenuItem1_Click);
			// 
			// frmPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(2582, 1055);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"frmPrincipal";
			this->Text = L"Bienvenido al Sistema de Gestión de un Hospital Inteligente";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &frmPrincipal::frmPrincipal_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void medicoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		frmMantMedicos^ ventanaMedicos = gcnew frmMantMedicos();
		ventanaMedicos->MdiParent = this;
		ventanaMedicos->Show();
	}
	private: System::Void verCitaMédicaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		frmVerCitas^ ventanaCitas = gcnew frmVerCitas();
		ventanaCitas->MdiParent = this;
		ventanaCitas->Show();
	}
	private: System::Void frmPrincipal_Load(System::Object^ sender, System::EventArgs^ e) {
		//Seteando la fecha/hora del sistema
		System::Windows::Forms::Timer^ timerFechaHora = gcnew System::Windows::Forms::Timer();
		timerFechaHora->Interval = 1000;  // 1 segundo
		timerFechaHora->Tick += gcnew System::EventHandler(this, &frmPrincipal::ActualizarFechaHora);
		timerFechaHora->Start();

		//Seteando al usuario conectado
		this->tssLblUsuario->Text = "Bienvenido: " + this->objPersona->getNombres() + " " + this->objPersona->getApellidos();
	}
		   //Metodos pesonalizados
		   void ActualizarFechaHora(System::Object^ sender, System::EventArgs^ e) {
			   this->tssLblFechaHora->Text = System::DateTime::Now.ToString("dd/MM/yyyy HH:mm:ss");
		   }
	private: System::Void equiposMédicosToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		frmReporteEquiposMedicos^ ventanaRptEquiposMedicos = gcnew frmReporteEquiposMedicos();
		ventanaRptEquiposMedicos->MdiParent = this;
		ventanaRptEquiposMedicos->Show();
	}
	private: System::Void gestiónDeEspecialidadesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		frmMantEspecialidades^ ventanaEspecialidades = gcnew frmMantEspecialidades();
		ventanaEspecialidades->MdiParent = this;
		ventanaEspecialidades->Show();
	}
	private: System::Void equiposMédicosToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
		frmMantEquiposMedicos^ ventanaEquiposMedicos = gcnew frmMantEquiposMedicos();
		ventanaEquiposMedicos->MdiParent = this;
		ventanaEquiposMedicos->Show();
	}
};
}
