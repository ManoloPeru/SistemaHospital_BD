#pragma once
#include "frmDetalleCita.h"

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
	/// Resumen de frmVerCitas
	/// </summary>
	public ref class frmVerCitas : public System::Windows::Forms::Form
	{
	public:
		frmVerCitas(void)
		{
			InitializeComponent();
			this->listaCitas = gcnew List<Cita^>();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmVerCitas()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnVerCitas;
	private: System::Windows::Forms::DateTimePicker^ dtpFecha;
	private: System::Windows::Forms::Panel^ pnlCitas;

	private: List<Cita^>^ listaCitas; //Listas de Citas
	// Agrega un diccionario para almacenar la posición y la cita correspondiente
	private: System::Collections::Generic::Dictionary<System::Drawing::Rectangle, Cita^>^ citasRectangles = gcnew System::Collections::Generic::Dictionary<System::Drawing::Rectangle, Cita^>();

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
			this->btnVerCitas = (gcnew System::Windows::Forms::Button());
			this->dtpFecha = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pnlCitas = (gcnew System::Windows::Forms::Panel());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btnVerCitas);
			this->groupBox1->Controls->Add(this->dtpFecha);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(14, 14);
			this->groupBox1->Margin = System::Windows::Forms::Padding(5);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(5);
			this->groupBox1->Size = System::Drawing::Size(1150, 117);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterios de Búsqueda";
			// 
			// btnVerCitas
			// 
			this->btnVerCitas->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnVerCitas->ForeColor = System::Drawing::Color::White;
			this->btnVerCitas->Location = System::Drawing::Point(516, 50);
			this->btnVerCitas->Margin = System::Windows::Forms::Padding(5);
			this->btnVerCitas->Name = L"btnVerCitas";
			this->btnVerCitas->Size = System::Drawing::Size(164, 53);
			this->btnVerCitas->TabIndex = 2;
			this->btnVerCitas->Text = L"Ver Citas";
			this->btnVerCitas->UseVisualStyleBackColor = false;
			this->btnVerCitas->Click += gcnew System::EventHandler(this, &frmVerCitas::btnVerCitas_Click);
			// 
			// dtpFecha
			// 
			this->dtpFecha->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpFecha->Location = System::Drawing::Point(220, 57);
			this->dtpFecha->Margin = System::Windows::Forms::Padding(5);
			this->dtpFecha->Name = L"dtpFecha";
			this->dtpFecha->Size = System::Drawing::Size(199, 34);
			this->dtpFecha->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 62);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Fecha :";
			// 
			// pnlCitas
			// 
			this->pnlCitas->BackColor = System::Drawing::SystemColors::Window;
			this->pnlCitas->Location = System::Drawing::Point(14, 141);
			this->pnlCitas->Margin = System::Windows::Forms::Padding(5);
			this->pnlCitas->Name = L"pnlCitas";
			this->pnlCitas->Size = System::Drawing::Size(1150, 487);
			this->pnlCitas->TabIndex = 1;
			this->pnlCitas->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmVerCitas::pnlCitas_Paint);
			this->pnlCitas->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmVerCitas::pnlCitas_MouseClick);
			// 
			// frmVerCitas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1179, 642);
			this->Controls->Add(this->pnlCitas);
			this->Controls->Add(this->groupBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"frmVerCitas";
			this->Text = L"Ver Citas";
			this->Load += gcnew System::EventHandler(this, &frmVerCitas::frmVerCitas_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnVerCitas_Click(System::Object^ sender, System::EventArgs^ e) {
		DateTime dFecha = this->dtpFecha->Value;
		int iFecha = dFecha.Year * 10000 + dFecha.Month * 100 + dFecha.Day;
		CitaController^ citaController = gcnew CitaController();
		this->listaCitas = citaController->listarCitasByFecha(iFecha);
		if (listaCitas->Count == 0)
		{
			MessageBox::Show("No se encontraron citas para la fecha consultada...!", "Mensaje de aviso",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		// Fuerza el redibujado del panel
		this->pnlCitas->Invalidate();
	}
	private: System::Void frmVerCitas_Load(System::Object^ sender, System::EventArgs^ e) {
		// Configuración del DateTimePicker
		this->dtpFecha->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
		this->dtpFecha->CustomFormat = "dd/MM/yyyy";
	}
	private: System::Void pnlCitas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ objGraphics = e->Graphics;
		// Limpia el diccionario de citas previas
		this->citasRectangles->Clear();

		// Verifica si la lista de citas está vacía
		if (listaCitas->Count == 0) {
			// Si no hay citas, no dibuja nada (deja el panel en blanco)
			return;
		}

		// Define las dimensiones del rectángulo
		int rectWidth = 200;
		int rectHeight = 75;
		int startX = 10;  // Posición x inicial
		int startY = 10;  // Posición y inicial
		int spacingY = 90; // Espacio entre rectángulos verticalmente
		int spacingX = 220; // Espacio entre columnas

		// Número de rectángulos por columna
		int rectsPerColumn = 5;
		int currentX = startX;
		int currentY = startY;

		System::Drawing::Font^ font = gcnew System::Drawing::Font("Arial", 10, System::Drawing::FontStyle::Bold); // Fuente para el texto

		// Pinta un rectángulo rojo por cada cita en listaCitas
		for (int i = 0; i < listaCitas->Count; i++) {
			// Dibuja el rectángulo
			objGraphics->FillRectangle(Brushes::Red, currentX, currentY + (i % rectsPerColumn) * spacingY, rectWidth, rectHeight);
			// Obtiene la cita actual
			Cita^ objCita = listaCitas[i];
			// Almacena la posición del rectángulo y la cita en el diccionario
			System::Drawing::Rectangle rect = System::Drawing::Rectangle(currentX, currentY + (i % rectsPerColumn) * spacingY, rectWidth, rectHeight);
			citasRectangles[rect] = objCita;

			// Prepara el texto con idCita, nombre del médico y nombre del paciente
			String^ textoCita = "ID: " + objCita->getIdCita() +
				"\nHora: " + objCita->getHora() +
				"\nMédico: " + objCita->getMedico()->getNombres() +
				"\nPaciente: " + objCita->getPaciente()->getNombres();

			// Dibuja el texto sobre el rectángulo
			objGraphics->DrawString(textoCita, font, Brushes::White, currentX + 5, currentY + (i % rectsPerColumn) * spacingY + 5);

			// Cambia de columna después de 5 rectángulos
			if ((i + 1) % rectsPerColumn == 0) {
				currentY = startY; // Reinicia Y a la parte superior
				currentX += spacingX; // Desplaza a la siguiente columna
			}
		}
	}
	private: System::Void pnlCitas_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		// Itera sobre el diccionario para verificar si el clic está dentro de algún rectángulo
		for each (System::Collections::Generic::KeyValuePair<System::Drawing::Rectangle, Cita^> pair in citasRectangles) {
			if (pair.Key.Contains(e->Location)) {
				Cita^ citaSeleccionada = pair.Value;

				// Abre el formulario de detalles y pasa la cita seleccionada
				frmDetalleCita^ detalleForm = gcnew frmDetalleCita(citaSeleccionada);
				detalleForm->ShowDialog();
				return;
			}
		}
	}
	
};
}
