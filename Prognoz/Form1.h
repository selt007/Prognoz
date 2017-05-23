//////////////////////
//created by *SeLT^///
//////////////////////
#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <windows.h>
#include <math.h>
#include "Form2.h"

#using <System.dll>
#using <System.Drawing.dll>
#using <System.Windows.Forms.dll>

double d,//плотность СДЯВ, т/м в кубе
	Ki,//коэффициент защиты людей от первичного облака
	Kii,//коэффициент защиты людей от вторичного облака
	Y1,Y2,//
	Sig1,Sig2,Siig1,Siig2,//для удобства расчета площади заражения
	n,//
	Li,//кол-во людей подвергшиеся заражению первичным облаком, чел/км в кв.
	Lii,//кол-во людей подвергшиеся заражению вторичным облаком, чел/км в кв.
	A,//плотность населения, кол-во чел
	Gm,//максимальная глубина заражения СДЯВ, км
	ni,//число пораженных первичным облаком
	nii,//число пораженных вторичным облаком
	nm,//общее число пораженных
	SOi,//площадь заражения первичным облаком
	SOii,//площадь заражения вторичным облаком
	N,//время, прошедшее после аварии, час
	Q,//общее кол-во СДЯВ, т
	Q1,//кол-во вещества в первичном облаке, т
	Q2,//кол-во вещества в вторичном облаке, т
	Cp,//удельная теплоемкость, ккал/кг.град
	Hisp,//удельная теплота испорения, ккал/кг
	t,//температура окружающего воздуха, градус цельсия
	tn,//разность температур жидкого СДЯВ до и после разрушения емкости, градус цельсия
	ti,//темп. СДЯВ после разрушения, градус цельсия
	to,//темп. СДЯВ до разрушения, градус цельсия
	tk,//темп. кипения СДЯВ, градус цельсия
	P,//давление насыщенного пара при 20 градусах по цельсию, мм.рт.ст.
	Pnas,//давление насыщенного пара при 0 градусов по цельсию, мм.рт.ст.
	W,//Скорость испарения СДЯВ, т/мин
	Tisp,//время полного испарения СДЯВ, час
	M,//молекулярная масса СДЯВ, г
	H,//Высота поддона, м
	h,//высота столба разлившейся жидкости, м
	u,//скорость приземного ветра, м/с
	Dpor,//пороговая токсодоза СДЯВ, мг.мин/л
	K1,//коэффициент, учитывающий влияние степени вертикальной устойчивости воздуха на 
	   //глубину распространения облака
	K2,//коэффициент, учитывающий влияние степени вертикальной устойчивости воздуха на 
	   //размывание в горизонтальном направлении перпендикулярно направлению ветра
	Gi,Gii,//Максимальная глубина первичного - Gi(вторичного - Gii) облака СДЯВ, км
	Sig,Siig,Siz,Siiz,//площадь зоны заражения первичным(i)(вторичным(ii)) облаком СДЯВ 
	                  //(g - в городе, z - за городом), км²
	R,//удаление химически опасного объекта от границы проектной застройки города по 
	  //направлению распространения облака зараженного воздуха
	HispTkip,//удельня теплота испарения при темп. кипения, градус цельсия
	CTkip,//удельная теплоемкость при темп. кипения, градус цельсия
	PTkip,//давление насыщенных паров при темп. кипения, градус цельсия
	V,//объем емкости с СДЯВ, м в кубе
	Sp,//площадь разлива СДЯВ, м²
	i;//i-ый способ защиты от СДЯВ

namespace Prognoz {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//Ввод данных в поле со списком
			//
			comboBox1->Items->Add("Азотная кислота");
			comboBox1->Items->Add("Аммиак");
			comboBox1->Items->Add("Ацетонитрил");
			comboBox1->Items->Add("Ацитоциангидрин");
			comboBox1->Items->Add("Водород хлористый");
			comboBox1->Items->Add("Водород фтористый");
			comboBox1->Items->Add("Водород цианистый");
			comboBox1->Items->Add("Диметиламин");
			comboBox1->Items->Add("Метиламин");
			comboBox1->Items->Add("Метил бромистый");
			comboBox1->Items->Add("Метил хлористый");
			comboBox1->Items->Add("Нитрил акриловой кислоты");
			comboBox1->Items->Add("Окись этилена");
			comboBox1->Items->Add("Сернистый ангидрид");
			comboBox1->Items->Add("Сероводород");
			comboBox1->Items->Add("Сероуглерод");
			comboBox1->Items->Add("Соляная кислота");
			comboBox1->Items->Add("Формальдегид");
			comboBox1->Items->Add("Фосген");
			comboBox1->Items->Add("Хлор");
			comboBox1->Items->Add("Хлорпикрин");
			
			comboBox2->Items->Add("Свободно");
			comboBox2->Items->Add("В поддон");

			comboBox3->Items->Add("Жидкость");
			comboBox3->Items->Add("Газ");

			comboBox4->Items->Add("Для инверсии");
			comboBox4->Items->Add("Для изотермии");
			comboBox4->Items->Add("Для конвекции");

			comboBox6->Items->Add("Открыто на местности");
			comboBox6->Items->Add("В транспорте");
			comboBox6->Items->Add("В производственных помещениях");
			comboBox6->Items->Add("В жилых и общественных помещениях");
			comboBox6->Items->Add("В убежищах");
			comboBox6->Items->Add("В средствах инд. защиты органов дыхания");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Button^  button1;
	public: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	public: System::Windows::Forms::TextBox^  kolSDAV;

	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::Label^  label5;
	public: System::Windows::Forms::TextBox^  visotapod;


	public: System::Windows::Forms::TextBox^  tempair;

	private: System::Windows::Forms::Label^  label6;
	public: System::Windows::Forms::TextBox^  skorvetr;

	public: System::Windows::Forms::ComboBox^  comboBox1;
	public: System::Windows::Forms::ComboBox^  comboBox2;
	public: System::Windows::Forms::GroupBox^  groupBox1;

	private: System::Windows::Forms::Label^  label8;
	public: System::Windows::Forms::ComboBox^  comboBox3;
	public: System::Windows::Forms::GroupBox^  sost;



	private: System::Windows::Forms::Label^  label10;
	public: System::Windows::Forms::TextBox^  plotnas;

	private: System::Windows::Forms::Label^  label11;

	public: System::Windows::Forms::ComboBox^  comboBox4;

private: System::Windows::Forms::Label^  label13;

private: System::Windows::Forms::Label^  label14;
public: 
public: System::Windows::Forms::TextBox^  obSDAV;
public: System::Windows::Forms::TextBox^  dav;

private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::Label^  label16;
public: System::Windows::Forms::TextBox^  tempdo;
private: 
private: System::Windows::Forms::Label^  label17;
public: 
private: System::Windows::Forms::Label^  label18;
public: System::Windows::Forms::TextBox^  tempposle;
public: System::Windows::Forms::ComboBox^  comboBox6;
private: System::Windows::Forms::Label^  label19;
public: 
private: System::Windows::Forms::Label^  label20;
public: System::Windows::Forms::TextBox^  vremposle;
private: System::Windows::Forms::Label^  label21;
public: 
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::Label^  label23;
public: System::Windows::Forms::TextBox^  udalobj;
private: System::Windows::Forms::Label^  label24;
public: 
private: 
private: 
private: 
public: 
private: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->kolSDAV = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->visotapod = (gcnew System::Windows::Forms::TextBox());
			this->tempair = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->skorvetr = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->sost = (gcnew System::Windows::Forms::GroupBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->plotnas = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->obSDAV = (gcnew System::Windows::Forms::TextBox());
			this->dav = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->tempdo = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->tempposle = (gcnew System::Windows::Forms::TextBox());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->vremposle = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->udalobj = (gcnew System::Windows::Forms::TextBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->sost->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(237, 315);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(210, 33);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Выход";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(9, 303);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(210, 45);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Подсчет";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(6, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(134, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Наименование СДЯВ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(6, 47);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(151, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Общее количество СДЯВ (т)";
			this->label2->Visible = false;
			// 
			// kolSDAV
			// 
			this->kolSDAV->Location = System::Drawing::Point(9, 63);
			this->kolSDAV->Name = L"kolSDAV";
			this->kolSDAV->Size = System::Drawing::Size(210, 20);
			this->kolSDAV->TabIndex = 5;
			this->kolSDAV->Visible = false;
			this->kolSDAV->TextChanged += gcnew System::EventHandler(this, &Form1::kolSDAV_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(6, 86);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(179, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Характер разлива СДЯВ на под - ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(6, 181);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(195, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Скорость ветра по данным прогноза";
			// 
			// visotapod
			// 
			this->visotapod->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->visotapod->Location = System::Drawing::Point(6, 15);
			this->visotapod->Name = L"visotapod";
			this->visotapod->Size = System::Drawing::Size(158, 20);
			this->visotapod->TabIndex = 9;
			this->visotapod->TextChanged += gcnew System::EventHandler(this, &Form1::visotapod_TextChanged);
			// 
			// tempair
			// 
			this->tempair->Location = System::Drawing::Point(9, 155);
			this->tempair->Name = L"tempair";
			this->tempair->Size = System::Drawing::Size(104, 20);
			this->tempair->TabIndex = 11;
			this->tempair->TextChanged += gcnew System::EventHandler(this, &Form1::tempair_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(6, 139);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(191, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Температура окружающего воздуха";
			// 
			// skorvetr
			// 
			this->skorvetr->Location = System::Drawing::Point(9, 197);
			this->skorvetr->Name = L"skorvetr";
			this->skorvetr->Size = System::Drawing::Size(175, 20);
			this->skorvetr->TabIndex = 13;
			this->skorvetr->TextChanged += gcnew System::EventHandler(this, &Form1::skorvetr_TextChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(9, 23);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(210, 21);
			this->comboBox1->TabIndex = 15;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(9, 115);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(210, 21);
			this->comboBox2->TabIndex = 16;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox2_SelectedIndexChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label21);
			this->groupBox1->Controls->Add(this->visotapod);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(231, 96);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(222, 40);
			this->groupBox1->TabIndex = 18;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Высота поддона";
			this->groupBox1->Visible = false;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label21->Location = System::Drawing::Point(165, 22);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(50, 13);
			this->label21->TabIndex = 46;
			this->label21->Text = L"метров";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(6, 99);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(132, 13);
			this->label8->TabIndex = 20;
			this->label8->Text = L"стилающей поверхности";
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(6, 13);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(210, 21);
			this->comboBox3->TabIndex = 21;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox3_SelectedIndexChanged);
			// 
			// sost
			// 
			this->sost->Controls->Add(this->comboBox3);
			this->sost->Location = System::Drawing::Point(231, 5);
			this->sost->Name = L"sost";
			this->sost->Size = System::Drawing::Size(222, 39);
			this->sost->TabIndex = 22;
			this->sost->TabStop = false;
			this->sost->Text = L"Агрегатное состояние СДЯВ";
			this->sost->Visible = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(233, 139);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(118, 13);
			this->label10->TabIndex = 25;
			this->label10->Text = L"Плотность населения";
			// 
			// plotnas
			// 
			this->plotnas->Location = System::Drawing::Point(237, 155);
			this->plotnas->Name = L"plotnas";
			this->plotnas->Size = System::Drawing::Size(133, 20);
			this->plotnas->TabIndex = 26;
			this->plotnas->TextChanged += gcnew System::EventHandler(this, &Form1::plotnas_TextChanged);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(6, 220);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(118, 13);
			this->label11->TabIndex = 27;
			this->label11->Text = L"Коэффициент К1 и K2";
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Location = System::Drawing::Point(9, 236);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(210, 21);
			this->comboBox4->TabIndex = 29;
			this->comboBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox4_SelectedIndexChanged);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(233, 181);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(87, 13);
			this->label13->TabIndex = 31;
			this->label13->Text = L"Способ защиты";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label14->Location = System::Drawing::Point(6, 47);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(183, 13);
			this->label14->TabIndex = 33;
			this->label14->Text = L"Объем емкости с СДЯВ (м в кубе)";
			this->label14->Visible = false;
			// 
			// obSDAV
			// 
			this->obSDAV->Location = System::Drawing::Point(9, 63);
			this->obSDAV->Name = L"obSDAV";
			this->obSDAV->Size = System::Drawing::Size(210, 20);
			this->obSDAV->TabIndex = 34;
			this->obSDAV->Visible = false;
			this->obSDAV->TextChanged += gcnew System::EventHandler(this, &Form1::obSDAV_TextChanged);
			// 
			// dav
			// 
			this->dav->Location = System::Drawing::Point(236, 63);
			this->dav->Name = L"dav";
			this->dav->Size = System::Drawing::Size(210, 20);
			this->dav->TabIndex = 35;
			this->dav->Visible = false;
			this->dav->TextChanged += gcnew System::EventHandler(this, &Form1::dav_TextChanged);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label15->Location = System::Drawing::Point(233, 47);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(139, 13);
			this->label15->TabIndex = 36;
			this->label15->Text = L"Давление газа в емкости";
			this->label15->Visible = false;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label16->Location = System::Drawing::Point(234, 47);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(179, 13);
			this->label16->TabIndex = 37;
			this->label16->Text = L"Темп-ра СДЯВ до и после аварии";
			this->label16->Visible = false;
			// 
			// tempdo
			// 
			this->tempdo->Location = System::Drawing::Point(269, 63);
			this->tempdo->Name = L"tempdo";
			this->tempdo->Size = System::Drawing::Size(57, 20);
			this->tempdo->TabIndex = 38;
			this->tempdo->Visible = false;
			this->tempdo->TextChanged += gcnew System::EventHandler(this, &Form1::tempdo_TextChanged);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label17->Location = System::Drawing::Point(233, 66);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(33, 13);
			this->label17->TabIndex = 39;
			this->label17->Text = L"t до:";
			this->label17->Visible = false;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label18->Location = System::Drawing::Point(329, 66);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(54, 13);
			this->label18->TabIndex = 40;
			this->label18->Text = L"t после:";
			this->label18->Visible = false;
			// 
			// tempposle
			// 
			this->tempposle->Location = System::Drawing::Point(389, 63);
			this->tempposle->Name = L"tempposle";
			this->tempposle->Size = System::Drawing::Size(57, 20);
			this->tempposle->TabIndex = 41;
			this->tempposle->Visible = false;
			this->tempposle->TextChanged += gcnew System::EventHandler(this, &Form1::tempposle_TextChanged);
			// 
			// comboBox6
			// 
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Location = System::Drawing::Point(236, 197);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(210, 21);
			this->comboBox6->TabIndex = 43;
			this->comboBox6->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox6_SelectedIndexChanged);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label19->Location = System::Drawing::Point(233, 220);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(176, 13);
			this->label19->TabIndex = 44;
			this->label19->Text = L"Время, прошедшее после аварии";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label20->Location = System::Drawing::Point(387, 243);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(60, 13);
			this->label20->TabIndex = 45;
			this->label20->Text = L"часа(-ов)";
			// 
			// vremposle
			// 
			this->vremposle->Location = System::Drawing::Point(237, 236);
			this->vremposle->Name = L"vremposle";
			this->vremposle->Size = System::Drawing::Size(152, 20);
			this->vremposle->TabIndex = 46;
			this->vremposle->TextChanged += gcnew System::EventHandler(this, &Form1::vremposle_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(371, 162);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(82, 13);
			this->label4->TabIndex = 47;
			this->label4->Text = L"чел/км в кв.";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(114, 162);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(114, 13);
			this->label7->TabIndex = 48;
			this->label7->Text = L"градусов цельсия";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(187, 204);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(29, 13);
			this->label9->TabIndex = 49;
			this->label9->Text = L"м/с";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label22->Location = System::Drawing::Point(233, 256);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(220, 13);
			this->label22->TabIndex = 50;
			this->label22->Text = L"Удаление аврийного объекта от населен-";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label23->Location = System::Drawing::Point(233, 269);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(177, 13);
			this->label23->TabIndex = 51;
			this->label23->Text = L"ного пункта в направлении ветра";
			// 
			// udalobj
			// 
			this->udalobj->Location = System::Drawing::Point(237, 285);
			this->udalobj->Name = L"udalobj";
			this->udalobj->Size = System::Drawing::Size(186, 20);
			this->udalobj->TabIndex = 52;
			this->udalobj->TextChanged += gcnew System::EventHandler(this, &Form1::udalobj_TextChanged);
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label24->Location = System::Drawing::Point(423, 292);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(23, 13);
			this->label24->TabIndex = 53;
			this->label24->Text = L"км";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gainsboro;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(459, 351);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->udalobj);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->vremposle);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->comboBox6);
			this->Controls->Add(this->tempposle);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->tempdo);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->dav);
			this->Controls->Add(this->obSDAV);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->plotnas);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->sost);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->skorvetr);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->tempair);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->kolSDAV);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Прогнозирование";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->sost->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 Application::Exit();
			 }
public: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (this->comboBox1->Text=="Азотная кислота")
			{this->sost->Visible = false;
			this->label2->Visible = true;
			this->kolSDAV->Visible = true;
			this->label16->Visible = true;
			this->label17->Visible = true;
			this->label18->Visible = true;
			this->tempdo->Visible = true;
			this->tempposle->Visible = true;
			this->label14->Visible = false;
			this->obSDAV->Visible = false;
			this->label15->Visible = false;
			this->dav->Visible = false;}
			 if (this->comboBox1->Text=="Аммиак")
			{this->sost->Visible = true;}
			 if (this->comboBox1->Text=="Ацетонитрил")
			{this->sost->Visible = false;
			this->label2->Visible = true;
			this->kolSDAV->Visible = true;
			this->label16->Visible = true;
			this->label17->Visible = true;
			this->label18->Visible = true;
			this->tempdo->Visible = true;
			this->tempposle->Visible = true;
			this->label14->Visible = false;
			this->obSDAV->Visible = false;
			this->label15->Visible = false;
			this->dav->Visible = false;}
			 if (this->comboBox1->Text=="Ацитоциангидрин")
			{this->sost->Visible = false;
			this->label2->Visible = true;
			this->kolSDAV->Visible = true;
			this->label16->Visible = true;
			this->label17->Visible = true;
			this->label18->Visible = true;
			this->tempdo->Visible = true;
			this->tempposle->Visible = true;
			this->label14->Visible = false;
			this->obSDAV->Visible = false;
			this->label15->Visible = false;
			this->dav->Visible = false;}
			 if (this->comboBox1->Text=="Водород хлористый")
			{this->sost->Visible = true;}
			 if (this->comboBox1->Text=="Водород фтористый")
			{this->sost->Visible = false;
			this->label2->Visible = true;
			this->kolSDAV->Visible = true;
			this->label16->Visible = true;
			this->label17->Visible = true;
			this->label18->Visible = true;
			this->tempdo->Visible = true;
			this->tempposle->Visible = true;
			this->label14->Visible = false;
			this->obSDAV->Visible = false;
			this->label15->Visible = false;
			this->dav->Visible = false;}
			 if (this->comboBox1->Text=="Водород цианистый")
			{this->sost->Visible = false;
			this->label2->Visible = true;
			this->kolSDAV->Visible = true;
			this->label16->Visible = true;
			this->label17->Visible = true;
			this->label18->Visible = true;
			this->tempdo->Visible = true;
			this->tempposle->Visible = true;
			this->label14->Visible = false;
			this->obSDAV->Visible = false;
			this->label15->Visible = false;
			this->dav->Visible = false;}
			 if (this->comboBox1->Text=="Диметиламин")
			{this->sost->Visible = true;}
			 if (this->comboBox1->Text=="Метиламин")
			{this->sost->Visible = true;}
			 if (this->comboBox1->Text=="Метил бромистый")
			{this->sost->Visible = false;
			this->label2->Visible = true;
			this->kolSDAV->Visible = true;
			this->label16->Visible = true;
			this->label17->Visible = true;
			this->label18->Visible = true;
			this->tempdo->Visible = true;
			this->tempposle->Visible = true;
			this->label14->Visible = false;
			this->obSDAV->Visible = false;
			this->label15->Visible = false;
			this->dav->Visible = false;}
			 if (this->comboBox1->Text=="Метил хлористый")
			{this->sost->Visible = true;}
			 if (this->comboBox1->Text=="Нитрил акриловой кислоты")
			{this->sost->Visible = false;
			this->label2->Visible = true;
			this->kolSDAV->Visible = true;
			this->label16->Visible = true;
			this->label17->Visible = true;
			this->label18->Visible = true;
			this->tempdo->Visible = true;
			this->tempposle->Visible = true;
			this->label14->Visible = false;
			this->obSDAV->Visible = false;
			this->label15->Visible = false;
			this->dav->Visible = false;}
			 if (this->comboBox1->Text=="Окись этилена")
			{this->sost->Visible = false;
			this->label2->Visible = true;
			this->kolSDAV->Visible = true;
			this->label16->Visible = true;
			this->label17->Visible = true;
			this->label18->Visible = true;
			this->tempdo->Visible = true;
			this->tempposle->Visible = true;
			this->label14->Visible = false;
			this->obSDAV->Visible = false;
			this->label15->Visible = false;
			this->dav->Visible = false;}
			 if (this->comboBox1->Text=="Сернистый ангидрид")
			{this->sost->Visible = true;}
			 if (this->comboBox1->Text=="Сероводород")
			{this->sost->Visible = true;}
			 if (this->comboBox1->Text=="Сероуглерод")
			{this->sost->Visible = false;
			this->label2->Visible = true;
			this->kolSDAV->Visible = true;
			this->label16->Visible = true;
			this->label17->Visible = true;
			this->label18->Visible = true;
			this->tempdo->Visible = true;
			this->tempposle->Visible = true;
			this->label14->Visible = false;
			this->obSDAV->Visible = false;
			this->label15->Visible = false;
			this->dav->Visible = false;}
			 if (this->comboBox1->Text=="Соляная кислота")
			{this->sost->Visible = false;}
			 if (this->comboBox1->Text=="Формальдегид")
			{this->sost->Visible = false;
			this->label2->Visible = true;
			this->kolSDAV->Visible = true;
			this->label16->Visible = true;
			this->label17->Visible = true;
			this->label18->Visible = true;
			this->tempdo->Visible = true;
			this->tempposle->Visible = true;
			this->label14->Visible = false;
			this->obSDAV->Visible = false;
			this->label15->Visible = false;
			this->dav->Visible = false;}
			 if (this->comboBox1->Text=="Фосген")
			{this->sost->Visible = true;}
			 if (this->comboBox1->Text=="Хлор")
			{this->sost->Visible = true;}
			 if (this->comboBox1->Text=="Хлорпикрин")
			{this->sost->Visible = false;
			this->label2->Visible = true;
			this->kolSDAV->Visible = true;
			this->label16->Visible = true;
			this->label17->Visible = true;
			this->label18->Visible = true;
			this->tempdo->Visible = true;
			this->tempposle->Visible = true;
			this->label14->Visible = false;
			this->obSDAV->Visible = false;
			this->label15->Visible = false;
			this->dav->Visible = false;}
			//
			//Присвоение значений к СДЯВ
			//
			if (comboBox1 -> Text == "Азотная кислота"){                 ////////////////////
				d = 1.518;
				M = 63.01;
				tk = 83.8;
				Dpor = 1.5;
				P = 47.8;
				Pnas = 12.0;
				PTkip = 760;
				Cp = 1;////////////
				CTkip = 1;//////////
				Hisp = 1;/////////
				HispTkip = 1;///////
			}
			if (comboBox1->Text=="Ацетонитрил"){                 ////////////////////
				d = 0.786;
				M = 41.5;
				tk = 81.3;
				Dpor = 21.6;
				P = 67.2;
				Pnas = 228;
				PTkip = 760;
				Cp = 1;//////////
				CTkip = 1;//////////
				Hisp = 1;//////////
				HispTkip = 1;/////////
			}
			if (comboBox1->Text=="Ацетоциангидрин"){                 ////////////////////
				d = 0.932;
				M = 85.1;
				tk = 120;
				Dpor = 0.54;
				P = 0.8;
				Pnas = 1;////////////
				PTkip = 760;
				Cp = 1;//////////
				CTkip = 1;/////////
				Hisp = 1;/////////
				HispTkip = 1;/////////
			}
			if (comboBox1->Text=="Водород фтористый"){                 ////////////////////
				d = 0.989;
				M = 20.01;
				tk = 19.52;
				Dpor = 4;
				P = 760;
				Pnas = 357;
				PTkip = 760;
				Cp = 1;///////////
				CTkip = 0.386;
				Hisp = 1;/////////
				HispTkip = 105.8;
			}
			if (comboBox1->Text=="Водород цианистый"){                 ////////////////////
				d = 0.687;
				M = 27.03;
				tk = 25.07;
				Dpor = 0.75;
				P = 620;
				Pnas = 240;
				PTkip = 760;
				Cp = 1;////////////
				CTkip = 0.618;
				Hisp = 1;/////////////
				HispTkip = 210.0;
			}
			if (comboBox1->Text=="Метил бромистый"){                 ////////////////////
				d = 1.732;
				M = 94.94;
				tk = 3.6;
				Dpor = 90;
				P = 760;
				Pnas = 656.6;
				PTkip = 760;
				Cp = 1;///////
				CTkip = 0.107;
				Hisp = 1;//////
				HispTkip = 102.4;
			}
			if (comboBox1->Text=="Нитрил акриловой кислоты"){                 ////////////////////
				d = 0.806;
				M = 53.06;
				tk = 77.3;
				Dpor = 0.75;
				P = 83.2;
				Pnas = 29.5;
				PTkip = 760;
				Cp = 1;//////////
				CTkip = 1;//////
				Hisp = 1;///////
				HispTkip = 1;/////
			}
			if (comboBox1->Text=="Окись этилена"){					      ////////////////////
				d = 0.882;
				M = 44.05;
				tk = 10.7;
				Dpor = 2.2;
				P = 760;
				Pnas = 501;
				PTkip = 760;
				Cp = 1;//////////
				CTkip = 0.471;
				Hisp = 1;////////
				HispTkip = 138.5;
			}
			if (comboBox1->Text=="Сероуглерод"){                 ////////////////////
				d = 1.263;
				M = 76.14;
				tk = 46.2;
				Dpor = 135;
				P = 297;
				Pnas = 127;
				PTkip = 760;
				Cp = 1;//////////
				CTkip = 1;//////
				Hisp = 1;///////
				HispTkip = 1;//////
			}
			if (comboBox1->Text=="Соляная кислота"){                 ////////////////////
				d = 1.198;
				M = 36.46;
				tk = 108.6;
				Dpor = 2.0;
				P = 210;
				Pnas = 66;
				PTkip = 760;
				Cp = 1;///////////
				CTkip = 1;//////
				Hisp = 1;//////
				HispTkip = 1;////////
			}
			if (comboBox1->Text=="Формальдегид"){                 ////////////////////
				d = 0.815;
				M = 30.03;
				tk = -19.0;
				Dpor = 0.6;
				P = 760;
				Pnas = 760;
				PTkip = 760;
				Cp = 1;/////////
				CTkip = 0.720;
				Hisp = 1;//////////
				HispTkip = 194.8;
			}
			if (comboBox1->Text=="Хлорпикрин"){                 ////////////////////
				d = 1.658;
				M = 164.38;
				tk = 112.3;
				Dpor = 0.02;
				P = 183;
				Pnas = 6.4;
				PTkip = 760;
				Cp = 1;/////////////
				CTkip = 1;/////////
				Hisp = 1;///////////
				HispTkip = 1;/////////
			}
			if (comboBox1->Text=="Аммиак"){                 ////////////////////
				M = 17.03;
				tk = -33.42;
				Dpor = 15;
				P = 760;
				Pnas = 760;
				PTkip = 760;
				Cp = 1.14;
				CTkip = 1.05;
				Hisp = 283.5;
				HispTkip = 327.3;
				
			}
			if (comboBox1->Text=="Водород хлористый"){                 ////////////////////
				M = 36.46;
				tk = -85.10;
				Dpor = 2;
				P = 760;
				Pnas = 760;
				PTkip = 760;
				Cp = 1;////////////
				CTkip = 0.386;
				Hisp = 1;//////////
				HispTkip = 105.8;
			}
			if (comboBox1->Text=="Диметиламин"){                 ////////////////////
				M = 45.09;
				tk = 6.9;
				Dpor = 4.8;
				P = 760;
				Pnas = 571;
				PTkip = 760;
				Cp = 1;//////////
				CTkip = 0.367;
				Hisp = 1;///////////
				HispTkip = 140.4;
			}
			if (comboBox1->Text=="Метиламин"){                 ////////////////////
				M = 31.06;
				tk = -6.5;
				Dpor = 4.8;
				P = 760;
				Pnas = 760;
				PTkip = 760;
				Cp = 1;//////////////
				CTkip = 0.416;
				Hisp = 1;////////////
				HispTkip = 198.6;
			}
			if (comboBox1->Text=="Метил хлористый"){                 ////////////////////
				M = 50.49;
				tk = -23.76;
				Dpor = 90;
				P = 760;
				Pnas = 760;
				PTkip = 760;
				Cp = 1;////////
				CTkip = 0.366;
				Hisp = 1;//////////
				HispTkip = 102.4;
			}
			if (comboBox1->Text=="Сернистый ангидрид"){                 ////////////////////
				M = 64.02;
				tk = -10.1;
				Dpor = 20.0;
				P = 760;
				Pnas = 760;
				PTkip = 760;
				Cp = 0.345;
				CTkip = 0.314;
				Hisp = 86.0;
				HispTkip = 98.9;
			}
			if (comboBox1->Text=="Сероводород"){                 ////////////////////
				M = 34.08;
				tk = -50.35;
				Dpor = 16.1;
				P = 760;
				Pnas = 760;
				PTkip = 760;
				Cp = 1;/////////
				CTkip = 0.446;
				Hisp = 1;////////
				HispTkip = 132.0;
			}
			if (comboBox1->Text=="Фосген"){                 ////////////////////
				M = 98.91;
				tk = 8.2;
				Dpor = 0.6;
				P = 760;
				Pnas = 760;
				PTkip = 760;
				Cp = 1;/////////
				CTkip = 0.240;
				Hisp = 1;////////
				HispTkip = 57.0;
			}
			if (comboBox1->Text=="Хлор"){                 ////////////////////
				M = 70.91;
				tk = -34.1;
				Dpor = 0.6;
				P = 760;
				Pnas = 760;
				PTkip = 760;
				Cp = 1;/////////
				CTkip = 0.225;
				Hisp = 1; ////////
				HispTkip = 68.7;
			}
			//
			//Видимость полей и лейблов связаных с агрегатным состоянием соляной кислоты
			//
			if (this->comboBox1->Text=="Соляная кислота")
			{
			this->label14->Visible = true;
			this->obSDAV->Visible = true;
			this->label2->Visible = false;
			this->kolSDAV->Visible = false;
			this->label16->Visible = false;
			this->label17->Visible = false;
			this->label18->Visible = false;
			this->tempdo->Visible = false;
			this->tempposle->Visible = false;
			this->label15->Visible = true;
			this->dav->Visible = true;
			}
		 }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////		
private: System::Void kolSDAV_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 Q = Convert::ToDouble(this->kolSDAV->Text);
		 }
private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (this->comboBox2->Text=="Свободно")
			{this->groupBox1->Visible = false;}
			 if (this->comboBox2->Text=="В поддон")
			{this->groupBox1->Visible = true;}
		 }
private: System::Void skorvetr_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 u = Convert::ToDouble(this->skorvetr->Text);
		 }
private: System::Void tempair_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 t = Convert::ToDouble(this->tempair->Text);
		 }
private: System::Void visotapod_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 H = Convert::ToDouble(this->visotapod->Text);
		 }
private: System::Void dav_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 P = Convert::ToDouble(this->dav->Text);
		 }
private: System::Void obSDAV_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 V = Convert::ToDouble(this->obSDAV->Text);
		 }
private: System::Void plotnas_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 A = Convert::ToDouble(this->plotnas->Text);
		 }
private: System::Void tempdo_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 to = Convert::ToDouble(this->tempdo->Text);
		 }
private: System::Void tempposle_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 ti = Convert::ToDouble(this->tempposle->Text);
		 }		
private: System::Void vremposle_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 N = Convert::ToDouble(this->vremposle->Text);
		 }
private: System::Void udalobj_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 R = Convert::ToDouble(this->udalobj->Text);
		 }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
public: System::Void comboBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 //
			 //Присвоение плотности по агрегатному состоянию
			 //
			    if (comboBox1->Text=="Аммиак"){                 ////////////////////
			 if (this->comboBox3->Text=="Жидкость"){
					d = 0.681;
				}
			 if (this->comboBox3->Text=="Газ"){
					d = 0.0008;
			 }}
				if (comboBox1->Text=="Водород хлористый"){                 ////////////////////
				if (this->comboBox3->Text=="Жидкость"){
					d = 1.639;
				}
				if (this->comboBox3->Text=="Газ"){
					d = 0.0016;
				}
			}
			if (comboBox1->Text=="Диметиламин"){                 ////////////////////
				if (this->comboBox3->Text=="Жидкость"){
					d = 0.680;
				}
				if (this->comboBox3->Text=="Газ"){
					d = 0.002;
				}
			}
			if (comboBox1->Text=="Метиламин"){                 ////////////////////
				if (this->comboBox3->Text=="Жидкость"){
					d = 0.699;
				}
				if (this->comboBox3->Text=="Газ"){
					d = 0.0014;
				}
			}
			if (comboBox1->Text=="Метил хлористый"){                 ////////////////////
				if (this->comboBox3->Text=="Жидкость"){
					d = 0.983;
				}
				if (this->comboBox3->Text=="Газ"){
					d = 0.0023;
				}
			}
			if (comboBox1->Text=="Сернистый ангидрид"){                 ////////////////////
				if (this->comboBox3->Text=="Жидкость"){
					d = 1.462;
				}
				if (this->comboBox3->Text=="Газ"){
					d = 0.0029;
				}
			}
			if (comboBox1->Text=="Сероводород"){                 ////////////////////
				if (this->comboBox3->Text=="Жидкость"){
					d = 0.964;
				}
				if (this->comboBox3->Text=="Газ"){
					d = 0.0015;
				}
			}
			if (comboBox1->Text=="Фосген"){                 ////////////////////
				if (this->comboBox3->Text=="Жидкость"){
					d = 1.432;
				}
				if (this->comboBox3->Text=="Газ"){
					d = 0.0035;
				}
			}
			if (comboBox1->Text=="Хлор"){                 ////////////////////
				if (this->comboBox3->Text=="Жидкость")
				{
					d = 1.558;
				}
				if (this->comboBox3->Text=="Газ")
				{
					d = 0.0032;
				}
			}
			//
			//Видимость полей и лейблов связаных с агрегатным состоянием
			//
			if (this->comboBox3->Text=="Жидкость"){
			this->label2->Visible = true;
			this->kolSDAV->Visible = true;
			this->label16->Visible = true;
			this->label17->Visible = true;
			this->label18->Visible = true;
			this->tempdo->Visible = true;
			this->tempposle->Visible = true;
			this->label14->Visible = false;
			this->obSDAV->Visible = false;
			this->label15->Visible = false;
			this->dav->Visible = false;
			}
			if (this->comboBox3->Text=="Газ"){
			this->label14->Visible = true;
			this->obSDAV->Visible = true;
			this->label2->Visible = false;
			this->kolSDAV->Visible = false;
			this->label16->Visible = false;
			this->label17->Visible = false;
			this->label18->Visible = false;
			this->tempdo->Visible = false;
			this->tempposle->Visible = false;
			this->label15->Visible = true;
			this->dav->Visible = true;
			}
};		 
private: System::Void comboBox4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 //
			 //Выбор первого кэффициента
			 //
			 if (this->comboBox4->Text=="Для инверсии")
			 {
				K1 = 0.015;
				K2 = 0.081;
			 }
			 if (this->comboBox4->Text=="Для изотермии")
			 {
				K1 = 0.04;
				K2 = 0.103;
			 }
			 if (this->comboBox4->Text=="Для конвекции")
			 {
				K1 = 0.08;
				K2 = 0.235;
			 }
			 /*if (this->comboBox4->Text=="")
			 {
				 if (u == 2) 
				 {

				 }
			 }*/
		 }
private: System::Void comboBox6_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (this->comboBox6->Text=="Открыто на местности")
			{ i = 1; }
			if (this->comboBox6->Text=="В транспорте")
			{ i = 2; }
			if (this->comboBox6->Text=="В производственных помещениях")
			{ i = 3; }
			if (this->comboBox6->Text=="В жилых и общественных помещениях")
			{ i = 4; }
			if (this->comboBox6->Text=="В убежищах")
			{ i = 5; }
			if (this->comboBox6->Text=="В средствах инд. защиты органов дыхания")
			{ i = 6; }
		 }
//////////////////////////////////////////////////////////////////////////////////////////////////////////// 
public: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		 //
		 //Коэффициенты защищенности по месту пребывания
		 //
			if ((i == 0) || (i == 1)) 
			{
			Ki = 0;
			Kii = 0;
			}
			if (i == 2) {
				if (N <= 0.25) {Ki = Kii = 0.85;}
				if ((N > 0.25) && (N <= 0.5)) {Ki = Kii = 0.75;}
				if ((N > 0.5) && (N <= 1)) {Ki = Kii = 0.41;}
			}
			if (i == 3) {
				if (N <= 0.25) {Ki = Kii = 0.67;}
				if ((N > 0.25) && (N <= 0.5)) {Ki = Kii = 0.5;}
				if ((N > 0.5) && (N <= 1)) {Ki = Kii = 0.23;}
				if ((N > 1) && (N <= 2)) {Ki = Kii = 0.09;}
				if ((N > 2) && (N <= 4)) {Ki = Kii = 0;}
			}
			if (i == 4) {
				if (N <= 0.25) {Ki = Kii = 0.97;}
				if ((N > 0.25) && (N <= 0.5)) {Ki = Kii = 0.92;}
				if ((N > 0.5) && (N <= 1)) {Ki = Kii = 0.80;}
				if ((N > 1) && (N <= 2)) {Ki = Kii = 0.38;}
				if ((N > 2) && (N <= 4)) {Ki = Kii = 0.09;}
			}
			if (i == 5) {
				if (N <= 0.25) {Ki = Kii = 1;}
				if ((N > 0.25) && (N <= 0.5)) {Ki = Kii = 1;}
				if ((N > 0.5) && (N <= 1)) {Ki = Kii = 1;}
				if ((N > 1) && (N <= 2)) {Ki = Kii = 1;}
				if ((N > 2) && (N <= 4)) {Ki = Kii = 0;}
			}
			if (i == 6) {
				if (N <= 0.25) {Ki = Kii = 0.7;}
				if ((N > 0.25) && (N <= 0.5)) {Ki = Kii = 0.7;}
				if ((N > 0.5) && (N <= 1)) {Ki = Kii = 0.7;}
				if ((N > 1) && (N <= 2)) {Ki = Kii = 0.7;}
				if ((N > 2) && (N <= 4)) {Ki = Kii = 0;}
			}
		 //
		 //Выбор формулы для подсчета кол-ва СДЯВ в облаке
		 //
			if (this->comboBox3->Text=="Газ")
			{
			 Q1 = P * d * V;
			 Q2 = Q - Q1;
			}	
			else
			 {
				 tn = ti - to;
				 Q1 = (Q * Cp * tn) / Hisp;
				 Q2 = Q - Q1;
			 }
			 if (this->comboBox1->Text=="Соляная кислота")
			 {
				Q1 = P * d * V;
				Q2 = Q - Q1;
			 }
			 //
			 //Площадь разлива СДЯВ
			 //
			 if (this->comboBox2->Text=="В поддон")
			 {
				 Sp = Q2 / (H - 0.02) * d;
			 }
			 else
			 {
				 Sp = Q2 / 0.05 * d;
			 }
			 //
			 //Скорость испарения разлившегося СДЯВ
			 //
			 W = 0.000001 * Sp * P * sqrt(M) * (5.38 + 2.7 * u);
			 //
			 //Время полного испарения СДЯВ
			 //
			 Tisp = Q2 / W;
			 //
			 //Глубина зоны поражения первичным облаком
			 //
			 Y1 = 1;
			 Gi = sqrt((15700 * Q1) / pow(K1, 1.5) * u * Dpor);

			 if ((Gi / u) > 740) {Y1 = 0.6 + 0.0145 * sqrt((Gi / u));}
			 else {Y1 = 1;}

			 Gi = sqrt((15700 * Q1 * Y1) / pow(K1, 1.5) * u * Dpor);
			 //
			 //Глубина зоны поражения вторичным облаком
			 //
			 if ((N < Tisp) && (Tisp <= 4)) {n = pow(N, 0.8);}
			 else {n = pow(Tisp, 0.8);}

			 Y2 = 1;
			 Gii = sqrt((15400 * W * n) / pow(K1, 1.5) * u * Dpor);

			 if ((Gii / u) > 740) {Y2 = 0.6 + 0.0145 * sqrt((Gii / u));}
			 else {Y2 = 1;}

			 Gii = sqrt((15400 * W * n * Y2) / pow(K1, 1.5) * u * Dpor);
			 //
			 //Максимальная глубина заражения от первичного и вторичного облака
			 //
			 if (Gii > Gi) {Gm = Gii + 0.5 * Gi;}
			 else {Gm = Gi + 0.5 * Gii;}
			 //
			 //Площадь зон заражения первичным и вторичным облаками
			 //
			 SOi = K2 * pow(Gi, 2) * pow(N, 0.2);
			 SOii = K2 * pow(Gii, 2) * pow(N, 0.2);
			 //
			 //Площади территории, подвергшейся заражению СДЯВ в городе и загородной зоне
			 //
			 /////////Первичным облаком//////////////////////////////////////////////
			 Sig1 = (2 * R - Gm) / Gm;
			 //Sig2 = Gm * R - pow(R, 2.0);
			 Sig2 = R * (Gi - R);
			 Sig = SOi / 3.14 * (3.14 / 2 + asin(Sig1)) + ((SOi * Sig1) / (1.6 * Gi)) * sqrt(Sig2);
			 Siz = SOi - Sig;
			 /////////Вторичным облаком//////////////////////////////////////////////
			 Siig1 = (2 * R - Gm) / Gm;
			 //Siig2 = Gm * R - pow(R, 2.0);
			 Siig2 = R * (Gii - R);
			 Siig = SOii / 3.14 * (3.14 / 2 + asin(Siig1)) + ((SOii * Siig1) / (1.6 * Gii)) * sqrt(Siig2);
			 Siiz = SOii - Siig;
			 //
			 //Число пораженных первичным и вторичным облаками
			 //
			 Li = A * SOi;
			 Lii = A * SOii;
			 if ((i == 0) || (i == 1)) {
			 ni = Li * (1 - Ki);
			 nii = (Lii - ni) * (1 - Kii);
			 }
			 else {
				 //ni = Li * (q * (1 - Ki));
				 //nii = Lii * (q * (1 - Kii));
			 }
			 //
			 //Общее число пораженных
			 //
			 nm = ni + nii;
			 //
			 //Вывод второй формы на экран с найдеными переменными
			 //
			 Form2 ^form2 = gcnew Form2();
			 form2->Show();
			 //this->Hide();
		 }
};
}