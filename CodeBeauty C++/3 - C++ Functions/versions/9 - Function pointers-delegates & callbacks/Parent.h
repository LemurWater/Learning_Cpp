//---------------------------------------------------------------------------

#ifndef ParentH
#define ParentH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TParentForm : public TForm
{
__published:	// IDE-managed Components
	TEdit *ParentImputField;
	TButton *SendMessageToButtonChild;
	TLabel *MessageLabel;
	void __fastcall SendMessageToButtonChildClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TParentForm(TComponent* Owner);
	void ShowMessageOnParent(AnsiString message);
};
//---------------------------------------------------------------------------
extern PACKAGE TParentForm *ParentForm;
//---------------------------------------------------------------------------
#endif
