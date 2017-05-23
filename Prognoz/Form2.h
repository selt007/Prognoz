#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>
#include <windows.h>
#include "Form1.h"

extern double Gm,//максимальная глубина заражения СДЯВ, км
			  ni,//число пораженных первичным облаком
			  nii,//число пораженных вторичным облаком
			  nm,//общее число пораженных
			  SOi,//площадь заражения первичным облаком
			  SOii,//площадь заражения вторичным облаком
			  Tisp,//время полного испарения СДЯВ, час
			  Gi,Gii,//Максимальная глубина первичного - Gi(вторичного - Gii) облака СДЯВ, км
			  Sig,Siig,Siz,Siiz;//площадь зоны заражения первичным(i)(вторичным(ii)) облаком СДЯВ 
								//(g - в городе, z - за городом), км²

namespace Prognoz {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form2(void)
		{
			InitializeComponent();
			this->textBox1->Text = Convert::ToString(Math::Round(Tisp, 2)) + Convert::ToString(" часа(ов)");
			this->textBox2->Text = Convert::ToString(Math::Round(Gi, 6)) + Convert::ToString(" км");
			this->textBox3->Text = Convert::ToString(Math::Round(Gii, 6)) + Convert::ToString(" км");
			this->textBox4->Text = Convert::ToString(Math::Round(Gm, 6)) + Convert::ToString(" км");
			this->textBox5->Text = Convert::ToString(Math::Round(Sig, 6)) + Convert::ToString(" кв. километров");
			this->textBox6->Text = Convert::ToString(Math::Round(Siig, 6)) + Convert::ToString(" кв. километров");
			this->textBox7->Text = Convert::ToString(Math::Round(SOi, 6)) + Convert::ToString(" кв. километров");
			this->textBox8->Text = Convert::ToString(Math::Round(SOii, 6)) + Convert::ToString(" кв. километров");
			this->textBox9->Text = Convert::ToString(Math::Round(Siz, 6)) + Convert::ToString(" кв. километров");
			this->textBox10->Text = Convert::ToString(Math::Round(Siiz, 6)) + Convert::ToString(" кв. километров");
			this->textBox11->Text = Convert::ToString(Math::Round(ni, 0)) + Convert::ToString(" человек(а)");
			this->textBox12->Text = Convert::ToString(Math::Round(nii, 0)) + Convert::ToString(" человек(а)");
			this->textBox13->Text = Convert::ToString(Math::Round(nm, 0)) + Convert::ToString(" человек(а)");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::Button^  button3;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form2::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(178, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Время полного испарения СДЯВ:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(217, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Глубина заражения первичным облаком:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 87);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(216, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Глубина заражения вторичным облаком:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 125);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(189, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Максимальная глубина заражения:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(247, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(223, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Площадь заражения первичным облаком:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(247, 48);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(222, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Площадь заражения вторичным облаком:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(9, 164);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(232, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Площадь города, подвергшаяся заражению";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(9, 216);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(232, 13);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Площадь города, подвергшаяся заражению";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(247, 87);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(224, 13);
			this->label9->TabIndex = 8;
			this->label9->Text = L"Площадь загородной зоны, подвергшаяся";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(247, 139);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(224, 13);
			this->label10->TabIndex = 9;
			this->label10->Text = L"Площадь загородной зоны, подвергшаяся";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(9, 177);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(114, 13);
			this->label11->TabIndex = 10;
			this->label11->Text = L"первичным облаком:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(9, 229);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(113, 13);
			this->label12->TabIndex = 11;
			this->label12->Text = L"вторичным облаком:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(247, 100);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(175, 13);
			this->label13->TabIndex = 12;
			this->label13->Text = L"заражению первичным облаком:";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(247, 152);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(174, 13);
			this->label14->TabIndex = 13;
			this->label14->Text = L"заражению вторичным облаком:";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(247, 191);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(215, 13);
			this->label15->TabIndex = 14;
			this->label15->Text = L"Число пораженных первичным облаком:";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(248, 230);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(214, 13);
			this->label16->TabIndex = 15;
			this->label16->Text = L"Число пораженных вторичным облаком:";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label17->Location = System::Drawing::Point(12, 278);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(166, 13);
			this->label17->TabIndex = 16;
			this->label17->Text = L"Общее число пораженных:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 25);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(214, 20);
			this->textBox1->TabIndex = 17;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 64);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(214, 20);
			this->textBox2->TabIndex = 18;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(12, 103);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(214, 20);
			this->textBox3->TabIndex = 19;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(12, 141);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(214, 20);
			this->textBox4->TabIndex = 20;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(12, 193);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(214, 20);
			this->textBox5->TabIndex = 21;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(12, 245);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(214, 20);
			this->textBox6->TabIndex = 22;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(250, 25);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(214, 20);
			this->textBox7->TabIndex = 23;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(250, 64);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(214, 20);
			this->textBox8->TabIndex = 24;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(250, 116);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(214, 20);
			this->textBox9->TabIndex = 25;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(250, 168);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(214, 20);
			this->textBox10->TabIndex = 26;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(250, 207);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(214, 20);
			this->textBox11->TabIndex = 27;
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(250, 246);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(214, 20);
			this->textBox12->TabIndex = 28;
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(184, 271);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(179, 20);
			this->textBox13->TabIndex = 29;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(12, 297);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(452, 35);
			this->button3->TabIndex = 30;
			this->button3->Text = L"ОК";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form2::button3_Click);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightGray;
			this->ClientSize = System::Drawing::Size(476, 339);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox13);
			this->Controls->Add(this->textBox12);
			this->Controls->Add(this->textBox11);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Результат прогнозирования";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }
};
}
