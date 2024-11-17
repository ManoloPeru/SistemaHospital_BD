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
	/// Resumen de frmReporteEquiposMedicos
	/// </summary>
	public ref class frmReporteEquiposMedicos : public System::Windows::Forms::Form
	{
	public:
		frmReporteEquiposMedicos(void)
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
		~frmReporteEquiposMedicos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chrtCantidadEquipos;
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
			this->chrtCantidadEquipos = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chrtCantidadEquipos))->BeginInit();
			this->SuspendLayout();
			// 
			// chrtCantidadEquipos
			// 
			chartArea1->Name = L"ChartArea1";
			this->chrtCantidadEquipos->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chrtCantidadEquipos->Legends->Add(legend1);
			this->chrtCantidadEquipos->Location = System::Drawing::Point(14, 14);
			this->chrtCantidadEquipos->Margin = System::Windows::Forms::Padding(5, 5, 5, 5);
			this->chrtCantidadEquipos->Name = L"chrtCantidadEquipos";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chrtCantidadEquipos->Series->Add(series1);
			this->chrtCantidadEquipos->Size = System::Drawing::Size(1038, 691);
			this->chrtCantidadEquipos->TabIndex = 0;
			this->chrtCantidadEquipos->Text = L"chart1";
			// 
			// frmReporteEquiposMedicos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1170, 754);
			this->Controls->Add(this->chrtCantidadEquipos);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5, 5, 5, 5);
			this->Name = L"frmReporteEquiposMedicos";
			this->Text = L"Reporte Equipos Médicos";
			this->Load += gcnew System::EventHandler(this, &frmReporteEquiposMedicos::frmReporteEquiposMedicos_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chrtCantidadEquipos))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmReporteEquiposMedicos_Load(System::Object^ sender, System::EventArgs^ e) {
		EquipoMedicoController^ reporteController = gcnew  EquipoMedicoController();
		List<ReporteEquipoMedico^>^ listaReporte = reporteController->contarCantidadEquipos();
		this->chrtCantidadEquipos->Series["Series1"]->Points->Clear();
		int iContador = 0;
		for each (ReporteEquipoMedico^ objeto in listaReporte)
		{
			this->chrtCantidadEquipos->Series["Series1"]->Points->Add(objeto->getCantidad());
			this->chrtCantidadEquipos->Series["Series1"]->Points[iContador]->AxisLabel = objeto->getEquipo();
			this->chrtCantidadEquipos->Series["Series1"]->Points[iContador]->LegendText = objeto->getEquipo();
			this->chrtCantidadEquipos->Series["Series1"]->Points[iContador]->Label = Convert::ToString(objeto->getCantidad());
			iContador++;
		}
	}
	};
}
