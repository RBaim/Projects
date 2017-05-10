#pragma once
#include "matrix.h"

Matrix A(1, 1), B(1, 1), Ans(1, 1);

namespace CppWinForm2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Label^  label3;


	private: System::Windows::Forms::ComboBox^  comboBox1;



	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  Изменить;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TabPage^  tabPage5;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::ComboBox^  comboBox4;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::ComboBox^  comboBox7;
	private: System::Windows::Forms::ComboBox^  comboBox6;
	private: System::Windows::Forms::ComboBox^  comboBox5;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::DataGridView^  dataGridView3;
	private: System::Windows::Forms::TabPage^  tabPage6;
	private: System::Windows::Forms::Label^  label15;


	private: System::ComponentModel::IContainer^  components;






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>

		void InitializeComponent(void)
		{
            System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->Изменить = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
            this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
            this->label14 = (gcnew System::Windows::Forms::Label());
            this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
            this->comboBox7 = (gcnew System::Windows::Forms::ComboBox());
            this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
            this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
            this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
            this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
            this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
            this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
            this->label15 = (gcnew System::Windows::Forms::Label());
            this->groupBox1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->tabControl1->SuspendLayout();
            this->tabPage1->SuspendLayout();
            this->tabPage2->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
            this->tabPage3->SuspendLayout();
            this->tabPage4->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
            this->tabPage5->SuspendLayout();
            this->tabPage6->SuspendLayout();
            this->SuspendLayout();
            // 
            // groupBox1
            // 
            this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->groupBox1->Controls->Add(this->Изменить);
            this->groupBox1->Controls->Add(this->button3);
            this->groupBox1->Controls->Add(this->label2);
            this->groupBox1->Controls->Add(this->label1);
            this->groupBox1->Controls->Add(this->numericUpDown2);
            this->groupBox1->Controls->Add(this->label3);
            this->groupBox1->Controls->Add(this->numericUpDown1);
            this->groupBox1->Location = System::Drawing::Point(29, 6);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(412, 166);
            this->groupBox1->TabIndex = 0;
            this->groupBox1->TabStop = false;
            // 
            // Изменить
            // 
            this->Изменить->Location = System::Drawing::Point(223, 69);
            this->Изменить->Name = L"Изменить";
            this->Изменить->Size = System::Drawing::Size(113, 26);
            this->Изменить->TabIndex = 3;
            this->Изменить->Text = L"Изменить";
            this->Изменить->UseVisualStyleBackColor = true;
            this->Изменить->Click += gcnew System::EventHandler(this, &MyForm::Изменить_Click);
            // 
            // button3
            // 
            this->button3->Location = System::Drawing::Point(223, 113);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(113, 26);
            this->button3->TabIndex = 2;
            this->button3->Text = L"Очистить";
            this->button3->UseVisualStyleBackColor = true;
            this->button3->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
            // 
            // label2
            // 
            this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(73, 97);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(71, 17);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Столбцов";
            this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
            // 
            // label1
            // 
            this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(83, 52);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(47, 17);
            this->label1->TabIndex = 1;
            this->label1->Text = L"Строк";
            this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
            // 
            // numericUpDown2
            // 
            this->numericUpDown2->Location = System::Drawing::Point(51, 117);
            this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->numericUpDown2->Name = L"numericUpDown2";
            this->numericUpDown2->Size = System::Drawing::Size(120, 22);
            this->numericUpDown2->TabIndex = 0;
            this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown2_ValueChanged);
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(109, 18);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(146, 17);
            this->label3->TabIndex = 1;
            this->label3->Text = L"Параметры матрицы";
            this->label3->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
            // 
            // numericUpDown1
            // 
            this->numericUpDown1->Location = System::Drawing::Point(51, 72);
            this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->numericUpDown1->Name = L"numericUpDown1";
            this->numericUpDown1->Size = System::Drawing::Size(120, 22);
            this->numericUpDown1->TabIndex = 0;
            this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown1_ValueChanged);
            // 
            // dataGridView1
            // 
            this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
            this->dataGridView1->Location = System::Drawing::Point(29, 207);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->RowTemplate->Height = 24;
            this->dataGridView1->Size = System::Drawing::Size(750, 368);
            this->dataGridView1->TabIndex = 1;
            this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
            this->dataGridView1->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
            this->dataGridView1->Click += gcnew System::EventHandler(this, &MyForm::dataGridView1_Click);
            // 
            // comboBox1
            // 
            this->comboBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->comboBox1->FormattingEnabled = true;
            this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Матрица A", L"Матрица B", L"Матрица Ans" });
            this->comboBox1->Location = System::Drawing::Point(564, 100);
            this->comboBox1->Name = L"comboBox1";
            this->comboBox1->Size = System::Drawing::Size(121, 24);
            this->comboBox1->TabIndex = 3;
            this->comboBox1->Text = L"(Не выбрано)";
            this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(591, 581);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(188, 39);
            this->button1->TabIndex = 4;
            this->button1->Text = L"Изменить матрицу";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // tabControl1
            // 
            this->tabControl1->Controls->Add(this->tabPage1);
            this->tabControl1->Controls->Add(this->tabPage2);
            this->tabControl1->Controls->Add(this->tabPage3);
            this->tabControl1->Controls->Add(this->tabPage4);
            this->tabControl1->Controls->Add(this->tabPage5);
            this->tabControl1->Controls->Add(this->tabPage6);
            this->tabControl1->Location = System::Drawing::Point(12, 12);
            this->tabControl1->Name = L"tabControl1";
            this->tabControl1->SelectedIndex = 0;
            this->tabControl1->Size = System::Drawing::Size(816, 656);
            this->tabControl1->TabIndex = 5;
            this->tabControl1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::tabControl1_SelectedIndexChanged);
            // 
            // tabPage1
            // 
            this->tabPage1->Controls->Add(this->label4);
            this->tabPage1->Controls->Add(this->groupBox1);
            this->tabPage1->Controls->Add(this->button1);
            this->tabPage1->Controls->Add(this->comboBox1);
            this->tabPage1->Controls->Add(this->dataGridView1);
            this->tabPage1->Location = System::Drawing::Point(4, 25);
            this->tabPage1->Name = L"tabPage1";
            this->tabPage1->Padding = System::Windows::Forms::Padding(3);
            this->tabPage1->Size = System::Drawing::Size(808, 627);
            this->tabPage1->TabIndex = 0;
            this->tabPage1->Text = L"Память";
            this->tabPage1->UseVisualStyleBackColor = true;
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(561, 75);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(126, 17);
            this->label4->TabIndex = 5;
            this->label4->Text = L"Текущая матрица";
            // 
            // tabPage2
            // 
            this->tabPage2->Controls->Add(this->label14);
            this->tabPage2->Controls->Add(this->dataGridView3);
            this->tabPage2->Controls->Add(this->comboBox7);
            this->tabPage2->Controls->Add(this->comboBox6);
            this->tabPage2->Controls->Add(this->comboBox5);
            this->tabPage2->Controls->Add(this->button2);
            this->tabPage2->Controls->Add(this->label13);
            this->tabPage2->Controls->Add(this->label12);
            this->tabPage2->Controls->Add(this->label11);
            this->tabPage2->Location = System::Drawing::Point(4, 25);
            this->tabPage2->Name = L"tabPage2";
            this->tabPage2->Padding = System::Windows::Forms::Padding(3);
            this->tabPage2->Size = System::Drawing::Size(808, 627);
            this->tabPage2->TabIndex = 1;
            this->tabPage2->Text = L"Расчеты";
            this->tabPage2->UseVisualStyleBackColor = true;
            // 
            // label14
            // 
            this->label14->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label14->AutoSize = true;
            this->label14->Location = System::Drawing::Point(349, 124);
            this->label14->Name = L"label14";
            this->label14->Size = System::Drawing::Size(104, 17);
            this->label14->TabIndex = 10;
            this->label14->Text = L"Результат Ans";
            // 
            // dataGridView3
            // 
            this->dataGridView3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView3->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
            this->dataGridView3->Location = System::Drawing::Point(30, 177);
            this->dataGridView3->Name = L"dataGridView3";
            this->dataGridView3->RowTemplate->Height = 24;
            this->dataGridView3->Size = System::Drawing::Size(750, 368);
            this->dataGridView3->TabIndex = 9;
            // 
            // comboBox7
            // 
            this->comboBox7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->comboBox7->FormattingEnabled = true;
            this->comboBox7->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"+", L"-", L"* ", L"^" });
            this->comboBox7->Location = System::Drawing::Point(181, 58);
            this->comboBox7->Name = L"comboBox7";
            this->comboBox7->Size = System::Drawing::Size(121, 24);
            this->comboBox7->TabIndex = 8;
            this->comboBox7->Text = L"(Не выбрано)";
            // 
            // comboBox6
            // 
            this->comboBox6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->comboBox6->FormattingEnabled = true;
            this->comboBox6->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Матрица A", L"Матрица B", L"Матрица Ans" });
            this->comboBox6->Location = System::Drawing::Point(318, 58);
            this->comboBox6->Name = L"comboBox6";
            this->comboBox6->Size = System::Drawing::Size(121, 24);
            this->comboBox6->TabIndex = 7;
            this->comboBox6->Text = L"(Не выбрано)";
            // 
            // comboBox5
            // 
            this->comboBox5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->comboBox5->FormattingEnabled = true;
            this->comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Матрица A", L"Матрица B", L"Матрица Ans" });
            this->comboBox5->Location = System::Drawing::Point(43, 58);
            this->comboBox5->Name = L"comboBox5";
            this->comboBox5->Size = System::Drawing::Size(121, 24);
            this->comboBox5->TabIndex = 6;
            this->comboBox5->Text = L"(Не выбрано)";
            // 
            // button2
            // 
            this->button2->Location = System::Drawing::Point(479, 58);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(113, 26);
            this->button2->TabIndex = 5;
            this->button2->Text = L"Расчет";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
            // 
            // label13
            // 
            this->label13->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label13->AutoSize = true;
            this->label13->Location = System::Drawing::Point(206, 29);
            this->label13->Name = L"label13";
            this->label13->Size = System::Drawing::Size(72, 17);
            this->label13->TabIndex = 4;
            this->label13->Text = L"Действие";
            // 
            // label12
            // 
            this->label12->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label12->AutoSize = true;
            this->label12->Location = System::Drawing::Point(326, 29);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(79, 17);
            this->label12->TabIndex = 3;
            this->label12->Text = L"Операнд 2";
            // 
            // label11
            // 
            this->label11->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->label11->AutoSize = true;
            this->label11->Location = System::Drawing::Point(64, 29);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(79, 17);
            this->label11->TabIndex = 2;
            this->label11->Text = L"Операнд 1";
            this->label11->Click += gcnew System::EventHandler(this, &MyForm::label11_Click);
            // 
            // tabPage3
            // 
            this->tabPage3->Controls->Add(this->label6);
            this->tabPage3->Controls->Add(this->label5);
            this->tabPage3->Controls->Add(this->textBox1);
            this->tabPage3->Controls->Add(this->comboBox2);
            this->tabPage3->Location = System::Drawing::Point(4, 25);
            this->tabPage3->Name = L"tabPage3";
            this->tabPage3->Size = System::Drawing::Size(808, 627);
            this->tabPage3->TabIndex = 2;
            this->tabPage3->Text = L"Определители";
            this->tabPage3->UseVisualStyleBackColor = true;
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Location = System::Drawing::Point(194, 21);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(105, 17);
            this->label6->TabIndex = 6;
            this->label6->Text = L"Определитель";
            this->label6->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(13, 21);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(126, 17);
            this->label5->TabIndex = 6;
            this->label5->Text = L"Текущая матрица";
            this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
            // 
            // textBox1
            // 
            this->textBox1->CausesValidation = false;
            this->textBox1->Location = System::Drawing::Point(187, 50);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(121, 22);
            this->textBox1->TabIndex = 5;
            // 
            // comboBox2
            // 
            this->comboBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->comboBox2->FormattingEnabled = true;
            this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Матрица A", L"Матрица B", L"Матрица Ans" });
            this->comboBox2->Location = System::Drawing::Point(18, 48);
            this->comboBox2->Name = L"comboBox2";
            this->comboBox2->Size = System::Drawing::Size(121, 24);
            this->comboBox2->TabIndex = 4;
            this->comboBox2->Text = L"(Не выбрано)";
            this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
            // 
            // tabPage4
            // 
            this->tabPage4->Controls->Add(this->dataGridView2);
            this->tabPage4->Controls->Add(this->label10);
            this->tabPage4->Controls->Add(this->label9);
            this->tabPage4->Controls->Add(this->comboBox4);
            this->tabPage4->Location = System::Drawing::Point(4, 25);
            this->tabPage4->Name = L"tabPage4";
            this->tabPage4->Size = System::Drawing::Size(808, 627);
            this->tabPage4->TabIndex = 3;
            this->tabPage4->Text = L"Обратная матрица";
            this->tabPage4->UseVisualStyleBackColor = true;
            // 
            // dataGridView2
            // 
            this->dataGridView2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView2->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
            this->dataGridView2->Location = System::Drawing::Point(30, 170);
            this->dataGridView2->Name = L"dataGridView2";
            this->dataGridView2->RowTemplate->Height = 24;
            this->dataGridView2->Size = System::Drawing::Size(750, 368);
            this->dataGridView2->TabIndex = 9;
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->Location = System::Drawing::Point(302, 113);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(162, 17);
            this->label10->TabIndex = 8;
            this->label10->Text = L"Обратная матрица Ans";
            this->label10->Click += gcnew System::EventHandler(this, &MyForm::label10_Click);
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->Location = System::Drawing::Point(320, 27);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(126, 17);
            this->label9->TabIndex = 7;
            this->label9->Text = L"Текущая матрица";
            // 
            // comboBox4
            // 
            this->comboBox4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->comboBox4->FormattingEnabled = true;
            this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Матрица A", L"Матрица B", L"Матрица Ans" });
            this->comboBox4->Location = System::Drawing::Point(323, 61);
            this->comboBox4->Name = L"comboBox4";
            this->comboBox4->Size = System::Drawing::Size(121, 24);
            this->comboBox4->TabIndex = 4;
            this->comboBox4->Text = L"(Не выбрано)";
            this->comboBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox4_SelectedIndexChanged);
            // 
            // tabPage5
            // 
            this->tabPage5->Controls->Add(this->label8);
            this->tabPage5->Controls->Add(this->textBox2);
            this->tabPage5->Controls->Add(this->label7);
            this->tabPage5->Controls->Add(this->comboBox3);
            this->tabPage5->Location = System::Drawing::Point(4, 25);
            this->tabPage5->Name = L"tabPage5";
            this->tabPage5->Padding = System::Windows::Forms::Padding(3);
            this->tabPage5->Size = System::Drawing::Size(808, 627);
            this->tabPage5->TabIndex = 4;
            this->tabPage5->Text = L"Ранг";
            this->tabPage5->UseVisualStyleBackColor = true;
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Location = System::Drawing::Point(252, 15);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(38, 17);
            this->label8->TabIndex = 9;
            this->label8->Text = L"Ранг";
            // 
            // textBox2
            // 
            this->textBox2->Location = System::Drawing::Point(211, 47);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(121, 22);
            this->textBox2->TabIndex = 8;
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Location = System::Drawing::Point(6, 15);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(126, 17);
            this->label7->TabIndex = 7;
            this->label7->Text = L"Текущая матрица";
            // 
            // comboBox3
            // 
            this->comboBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->comboBox3->FormattingEnabled = true;
            this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Матрица A", L"Матрица B", L"Матрица Ans" });
            this->comboBox3->Location = System::Drawing::Point(6, 45);
            this->comboBox3->Name = L"comboBox3";
            this->comboBox3->Size = System::Drawing::Size(121, 24);
            this->comboBox3->TabIndex = 5;
            this->comboBox3->Text = L"(Не выбрано)";
            this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox3_SelectedIndexChanged);
            // 
            // tabPage6
            // 
            this->tabPage6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tabPage6.BackgroundImage")));
            this->tabPage6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->tabPage6->Controls->Add(this->label15);
            this->tabPage6->Location = System::Drawing::Point(4, 25);
            this->tabPage6->Name = L"tabPage6";
            this->tabPage6->Size = System::Drawing::Size(808, 627);
            this->tabPage6->TabIndex = 5;
            this->tabPage6->Text = L"О программе";
            this->tabPage6->UseVisualStyleBackColor = true;
            // 
            // label15
            // 
            this->label15->AutoSize = true;
            this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label15->Location = System::Drawing::Point(270, 473);
            this->label15->Name = L"label15";
            this->label15->Size = System::Drawing::Size(264, 96);
            this->label15->TabIndex = 0;
            this->label15->Text = L" radmir200@mail.ru\r\n\r\n             2017";
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->AutoValidate = System::Windows::Forms::AutoValidate::Disable;
            this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
            this->ClientSize = System::Drawing::Size(834, 669);
            this->Controls->Add(this->tabControl1);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->MaximumSize = System::Drawing::Size(856, 720);
            this->MinimumSize = System::Drawing::Size(856, 720);
            this->Name = L"MyForm";
            this->Text = L"Матрицы";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->tabControl1->ResumeLayout(false);
            this->tabPage1->ResumeLayout(false);
            this->tabPage1->PerformLayout();
            this->tabPage2->ResumeLayout(false);
            this->tabPage2->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
            this->tabPage3->ResumeLayout(false);
            this->tabPage3->PerformLayout();
            this->tabPage4->ResumeLayout(false);
            this->tabPage4->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
            this->tabPage5->ResumeLayout(false);
            this->tabPage5->PerformLayout();
            this->tabPage6->ResumeLayout(false);
            this->tabPage6->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion
	private: void izm()
	{
		switch (comboBox1->SelectedIndex)
		{
		case(0):A.newmatr(Convert::ToInt32(numericUpDown1->Value), Convert::ToInt32(numericUpDown2->Value)); break;
		case(1):B.newmatr(Convert::ToInt32(numericUpDown1->Value), Convert::ToInt32(numericUpDown2->Value)); break;
		case(2):Ans.newmatr(Convert::ToInt32(numericUpDown1->Value), Convert::ToInt32(numericUpDown2->Value));
		}
	}
	private: void showosn(Matrix &A)
	{
		int n, m;
		n = A.razstrok(); m = A.razstolb();
		dataGridView1->ColumnCount = m;
		dataGridView1->RowCount = n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				dataGridView1->TopLeftHeaderCell->Value = "Матрица";
				dataGridView1->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
				dataGridView1->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
				dataGridView1->Rows[i]->Cells[j]->Value = A(i, j);
			}
		}
		dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		dataGridView1->AutoResizeColumns();
	}

	private: void show()
	{
		switch (comboBox1->SelectedIndex)
		{
		case(0):showosn(A); break;
		case(1):showosn(B); break;
		case(2):showosn(Ans);
		}
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		numericUpDown1->Value = 1;
		numericUpDown2->Value = 1;
		show();
	}
	private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void numericUpDown2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void памятьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		double p;
		if (!Double::TryParse(Convert::ToString(dataGridView1->CurrentCell->Value), p))
		{
			MessageBox::Show("Некорректный ввод", "Ошибка");
			dataGridView1->CurrentCell->Value = "0";
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		switch (comboBox1->SelectedIndex)
		{
		case(0):A.null(); break;
		case(1):B.null(); break;
		case(2):Ans.null();
		}
		show();
	}
	private: System::Void Изменить_Click(System::Object^  sender, System::EventArgs^  e) {
		izm();
		show();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		int n, m;
		dataGridView1->EndEdit();
		switch (comboBox1->SelectedIndex)
		{
		case(0):n = A.razstrok(), m = A.razstolb();
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					A.formelem(i, j, Convert::ToDouble(dataGridView1->Rows[i]->Cells[j]->Value));
				}
			} break;
		case(1):n = B.razstrok(), m = B.razstolb();
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					B.formelem(i, j, Convert::ToDouble(dataGridView1->Rows[i]->Cells[j]->Value));
				}
			} break;
		case(2):n = Ans.razstrok(), m = Ans.razstolb();
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					Ans.formelem(i, j, Convert::ToDouble(dataGridView1->Rows[i]->Cells[j]->Value));
				}
			}
		}
	}
	private: System::Void dataGridView1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void notifyIcon1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	}
	private: System::Void folderBrowserDialog1_HelpRequest(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		dataGridView1->AllowUserToAddRows = false;
		dataGridView1->AllowUserToDeleteRows = false;
		dataGridView2->Enabled = false;
		dataGridView3->Enabled = false;
		textBox1->Enabled = false;
		textBox2->Enabled = false;
	}
	private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
	}
			 void determ()
			 {
				 switch (comboBox2->SelectedIndex)
				 {
				 case 0:textBox1->Text = Convert::ToString(A.det()); break;
				 case 1:textBox1->Text = Convert::ToString(B.det()); break;
				 case 2:textBox1->Text = Convert::ToString(Ans.det());
				 }
			 }
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		determ();
	}
	private: System::Void tabControl1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		switch (tabControl1->SelectedIndex)
		{
		case 0:show(); break;
		case 2: determ(); break;
		case 3: izm2(); break;
		case 4: ranger();
		}
	}
	private:void ranger()
	{
		switch (comboBox3->SelectedIndex)
		{
		case 0:textBox2->Text = Convert::ToString(A.rang()); break;
		case 1:textBox2->Text = Convert::ToString(B.rang()); break;
		case 2:textBox2->Text = Convert::ToString(Ans.rang());
		}
	}
	private: System::Void comboBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		ranger();
	}
	private: System::Void label10_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: void izm2obr(Matrix &A)
	{
		int n, m;
		Ans = A.obrat(); n = Ans.razstrok(); m = Ans.razstolb();
		dataGridView2->ColumnCount = m;
		dataGridView2->RowCount = n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				//dataGridView2->TopLeftHeaderCell->Value = "Матрица";
				dataGridView2->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
				dataGridView2->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
				dataGridView2->Rows[i]->Cells[j]->Value = Ans(i, j);
			}
		}
	}
	private: void izm2()
	{
		switch (comboBox4->SelectedIndex)
		{
		case(0):izm2obr(A); break;
		case(1):izm2obr(B); break;
		case(2):izm2obr(Ans);
		}
	}
	private: System::Void comboBox4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		izm2();
	}
	private: System::Void label11_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private:void rasch(Matrix &A, Matrix &B, char d)
	{
		int n;
		switch (d)
		{
		case'+': Ans = A + B; break;
		case'-': Ans = A - B; break;
		case'*': Ans = A * B; break;
		case '^': if (B.razstolb() == 1 && B.razstrok() == 1 && (Int32::TryParse(Convert::ToString(B(0, 0)), n)) && B(0, 0) > 0)
		{
			Ans.newmatr(A.razstrok(), A.razstolb());
			Ans.eden();
			for (int i = 0; i < n; i++)
			{
				Ans = Ans * A;
			}
		}
				  else
				  {
					  MessageBox::Show("Матрица должна быть целым числом > 0", "Ошибка");
				  }
		}
	}
	private:void ras()
	{
		switch (comboBox5->SelectedIndex)
		{
		case 0:
			switch (comboBox6->SelectedIndex)
			{
			case 0: switch (comboBox7->SelectedIndex)
			{
			case 0:rasch(A, A, '+'); break;
			case 1:rasch(A, A, '-'); break;
			case 2:rasch(A, A, '*'); break;
			case 3:rasch(A, A, '^');
			} break;
			case 1: switch (comboBox7->SelectedIndex)
			{
			case 0:rasch(A, B, '+'); break;
			case 1:rasch(A, B, '-'); break;
			case 2:rasch(A, B, '*'); break;
			case 3:rasch(A, B, '^');
			} break;
			case 2: switch (comboBox7->SelectedIndex)
			{
			case 0:rasch(A, Ans, '+'); break;
			case 1:rasch(A, Ans, '-'); break;
			case 2:rasch(A, Ans, '*'); break;
			case 3:rasch(A, Ans, '^');
			}
			} break;
		case 1:
			switch (comboBox6->SelectedIndex)
			{
			case 0: switch (comboBox7->SelectedIndex)
			{
			case 0:rasch(B, A, '+'); break;
			case 1:rasch(B, A, '-'); break;
			case 2:rasch(B, A, '*'); break;
			case 3:rasch(B, A, '^');
			} break;
			case 1: switch (comboBox7->SelectedIndex)
			{
			case 0:rasch(B, B, '+'); break;
			case 1:rasch(B, B, '-'); break;
			case 2:rasch(B, B, '*'); break;
			case 3:rasch(B, B, '^');
			} break;
			case 2: switch (comboBox7->SelectedIndex)
			{
			case 0:rasch(B, Ans, '+'); break;
			case 1:rasch(B, Ans, '-'); break;
			case 2:rasch(B, Ans, '*'); break;
			case 3:rasch(B, Ans, '^');
			}
			} break;
		case 2:
			switch (comboBox6->SelectedIndex)
			{
			case 0: switch (comboBox7->SelectedIndex)
			{
			case 0:rasch(Ans, A, '+'); break;
			case 1:rasch(Ans, A, '-'); break;
			case 2:rasch(Ans, A, '*'); break;
			case 3:rasch(Ans, A, '^');
			} break;
			case 1: switch (comboBox7->SelectedIndex)
			{
			case 0:rasch(Ans, B, '+'); break;
			case 1:rasch(Ans, B, '-'); break;
			case 2:rasch(Ans, B, '*'); break;
			case 3:rasch(Ans, B, '^');
			} break;
			case 2: switch (comboBox7->SelectedIndex)
			{
			case 0:rasch(Ans, Ans, '+'); break;
			case 1:rasch(Ans, Ans, '-'); break;
			case 2:rasch(Ans, Ans, '*'); break;
			case 3:rasch(Ans, Ans, '^');
			}
			}
		}
	}
	private: void showr()
	{
		int n, m;
		n = Ans.razstrok(); m = Ans.razstolb();
		dataGridView3->ColumnCount = m;
		dataGridView3->RowCount = n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				//dataGridView3->TopLeftHeaderCell->Value = "Матрица";
				dataGridView3->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
				dataGridView3->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
				dataGridView3->Rows[i]->Cells[j]->Value = Ans(i, j);
			}
		}
	}
	private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
		ras();
		showr();
	}
	};
}
