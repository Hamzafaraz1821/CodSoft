#pragma once
#include<cstdlib>
#include<time.h>
#include<stdlib.h>

namespace CppCLRWinFormsProject {

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
			//TODO: Add the constructor code here
			//
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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBoxGuess;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label1;

	protected:

	private:

		int randomNum(void)
		{
			srand(time(0));
			int random = rand() % 100 + 1;
			return random;
		}
	private: System::ComponentModel::IContainer^ components;
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
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->textBoxGuess = (gcnew System::Windows::Forms::TextBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   // 
			   // button1
			   // 
			   this->button1->BackColor = System::Drawing::Color::AliceBlue;
			   this->button1->ForeColor = System::Drawing::Color::Black;
			   this->button1->Location = System::Drawing::Point(151, 183);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(96, 40);
			   this->button1->TabIndex = 0;
			   this->button1->Text = L"Guess";
			   this->button1->UseVisualStyleBackColor = false;
			   this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			   this->button1->MouseLeave += gcnew System::EventHandler(this, &Form1::button1_MouseLeave);
			   this->button1->MouseHover += gcnew System::EventHandler(this, &Form1::button1_MouseHover);
			   // 
			   // textBoxGuess
			   // 
			   this->textBoxGuess->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				   static_cast<System::Int32>(static_cast<System::Byte>(192)));
			   this->textBoxGuess->Location = System::Drawing::Point(226, 44);
			   this->textBoxGuess->Margin = System::Windows::Forms::Padding(10);
			   this->textBoxGuess->Name = L"textBoxGuess";
			   this->textBoxGuess->Size = System::Drawing::Size(192, 26);
			   this->textBoxGuess->TabIndex = 1;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			   this->label1->Location = System::Drawing::Point(9, 81);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(105, 29);
			   this->label1->TabIndex = 2;
			   this->label1->Text = L"Result:";
			   // 
			   // button2
			   // 
			   this->button2->BackColor = System::Drawing::Color::Orange;
			   this->button2->ForeColor = System::Drawing::Color::Black;
			   this->button2->Location = System::Drawing::Point(314, 384);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(98, 44);
			   this->button2->TabIndex = 3;
			   this->button2->Text = L"Exit";
			   this->button2->UseVisualStyleBackColor = false;
			   this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			   this->button2->MouseLeave += gcnew System::EventHandler(this, &Form1::button2_MouseLeave);
			   this->button2->MouseHover += gcnew System::EventHandler(this, &Form1::button2_MouseHover);
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display Semib", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			   this->label2->Location = System::Drawing::Point(97, 83);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(17, 27);
			   this->label2->TabIndex = 4;
			   this->label2->Text = L".";
			   this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(155)),
				   static_cast<System::Int32>(static_cast<System::Byte>(41)));
			   this->label3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label3->Location = System::Drawing::Point(12, 37);
			   this->label3->Name = L"label3";
			   this->label3->Padding = System::Windows::Forms::Padding(0, 3, 0, 3);
			   this->label3->Size = System::Drawing::Size(174, 33);
			   this->label3->TabIndex = 5;
			   this->label3->Text = L"Enter Your Guess:";
			   // 
			   // Form1
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->AutoSize = true;
			   this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(97)),
				   static_cast<System::Int32>(static_cast<System::Byte>(255)));
			   this->ClientSize = System::Drawing::Size(424, 440);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->button2);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->textBoxGuess);
			   this->Controls->Add(this->button1);
			   this->Location = System::Drawing::Point(149, 192);
			   this->Name = L"Form1";
			   this->Text = L"Guessing Game";
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void button1_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		this->button1->ForeColor = System::Drawing::Color::Black;
		this->button1->BackColor = System::Drawing::Color::LightBlue;
	}
	private: System::Void button1_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		this->button1->ForeColor = System::Drawing::Color::Black;
		this->button1->BackColor = System::Drawing::Color::AliceBlue;
	}

		   int random = randomNum();
	private:

		int guess;

		void CheckGuess() {
			if (Int32::TryParse(textBoxGuess->Text, guess)) {
				if (guess == random) {
					this->label2->Text = L"Congratulations! You guessed correctly!";
				}
				else if (guess < random) {
					this->label2->Text = L"Try a higher number.";
				}
				else {
					this->label2->Text = L"Try a lower number.";
				}
			}
			else {
				this->label2->Text = L"Invalid Input. Please enter a valid integer.";
			}
		}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		CheckGuess();
	}


	private: System::Void button2_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		this->button2->BackColor = System::Drawing::Color::OrangeRed;
	}
	private: System::Void button2_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		this->button2->BackColor = System::Drawing::Color::Orange;

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
