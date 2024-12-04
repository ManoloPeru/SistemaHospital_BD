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

	/// <summary>
	/// Resumen de frmReporteCitas
	/// </summary>
	public ref class frmReporteCitas : public System::Windows::Forms::Form
	{
	public:
		frmReporteCitas(void)
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
		~frmReporteCitas()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chrtCantidadCitas;
	protected:

	protected:

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chrtCantidadCitas = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chrtCantidadCitas))->BeginInit();
			this->SuspendLayout();
			// 
			// chrtCantidadCitas
			// 
			chartArea1->Name = L"ChartArea1";
			this->chrtCantidadCitas->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chrtCantidadCitas->Legends->Add(legend1);
			this->chrtCantidadCitas->Location = System::Drawing::Point(14, 14);
			this->chrtCantidadCitas->Margin = System::Windows::Forms::Padding(5);
			this->chrtCantidadCitas->Name = L"chrtCantidadCitas";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chrtCantidadCitas->Series->Add(series1);
			this->chrtCantidadCitas->Size = System::Drawing::Size(1069, 616);
			this->chrtCantidadCitas->TabIndex = 0;
			this->chrtCantidadCitas->Text = L"chart1";
			// 
			// frmReporteCitas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1093, 642);
			this->Controls->Add(this->chrtCantidadCitas);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"frmReporteCitas";
			this->Text = L"Reporte de Citas";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &frmReporteCitas::frmReporteCitas_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chrtCantidadCitas))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmReporteCitas_Load(System::Object^ sender, System::EventArgs^ e) {
		CitaController^ reporteController = gcnew  CitaController();
		List<ReporteCita^>^ listaReporte = reporteController->contarCantidadCitas();
		this->chrtCantidadCitas->Series["Series1"]->Points->Clear();
		int iContador = 0;
		for each (ReporteCita ^ objeto in listaReporte)
		{
			this->chrtCantidadCitas->Series["Series1"]->Points->Add(objeto->getCantidad());
			this->chrtCantidadCitas->Series["Series1"]->Points[iContador]->AxisLabel = objeto->getFecha();
			this->chrtCantidadCitas->Series["Series1"]->Points[iContador]->LegendText = objeto->getFecha();
			this->chrtCantidadCitas->Series["Series1"]->Points[iContador]->Label = Convert::ToString(objeto->getCantidad());
			iContador++;
		}

	}
	};
}
