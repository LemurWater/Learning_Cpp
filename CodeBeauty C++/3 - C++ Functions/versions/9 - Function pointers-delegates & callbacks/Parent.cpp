//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Parent.h"
#include "Child.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TParentForm *ParentForm;
//---------------------------------------------------------------------------
__fastcall TParentForm::TParentForm(TComponent* Owner)
	: TForm(Owner)
{
}

void TParentForm::ShowMessageOnParent(AnsiString message) {
	MessageLabel->Text= message;
}

//---------------------------------------------------------------------------
void __fastcall TParentForm::SendMessageToButtonChildClick(TObject *Sender)
{
	void (__closure *funcPtr)(AnsiString) =  ShowMessageOnParent;

	TChildForm *childForm=new TChildForm(nullptr, ParentImputField->Text, funcPtr);
	childForm->Show();
}
//---------------------------------------------------------------------------
