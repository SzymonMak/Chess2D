/***************************************************************
 * Name:      Chess2DMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2024-01-07
 * Copyright:  ()
 * License:
 **************************************************************/

#include "Chess2DMain.h"
#include <wx/msgdlg.h>
#include <wx/log.h>



//(*InternalHeaders(Chess2DDialog)
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format){
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f ){
        #if defined(__WXMSW__)
                wxbuild << _T("-Windows");
        #elif defined(__UNIX__)
                wxbuild << _T("-Linux");
        #endif

        #if wxUSE_UNICODE
                wxbuild << _T("-Unicode build");
        #else
                wxbuild << _T("-ANSI build");
        #endif // wxUSE_UNICODE
    }

    return wxbuild;
}


 // Declaration of board and images
wxBitmapButton* board[8][8];
wxBitmap images[2][13];
Board* _board = new Board();



 //Counting
int counter=0;

//(*IdInit(Chess2DDialog)
const long Chess2DDialog::ID_BITMAPBUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Chess2DDialog,wxDialog)
    //(*EventTable(Chess2DDialog)
    //*)
END_EVENT_TABLE()

Chess2DDialog::Chess2DDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Chess2DDialog)
    wxFlexGridSizer* FlexGridSizer1;
    wxGridSizer* GridSizer1;

    Create(parent, id, _("wxWidgets app"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
    GridSizer1 = new wxGridSizer(8, 8, -4, -4);
    BitmapButton1 = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("images\\Pieces\\brB.png"))), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    GridSizer1->Add(BitmapButton1, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer1->Add(GridSizer1, 1, wxALL|wxEXPAND, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Chess2DDialog::OnBitmapButton1Click);
    //*)


    { // ChessBoard Display
    images[0][0] = wxBitmap(wxImage("images/D.jpg"));
    images[0][1] = wxBitmap(wxImage(_T("images/Pieces/bpB.png")));
    images[0][2] = wxBitmap(wxImage(_T("images/Pieces/bpD.png")));
    images[0][3] = wxBitmap(wxImage(_T("images/Pieces/brB.png")));
    images[0][4] = wxBitmap(wxImage(_T("images/Pieces/brD.png")));
    images[0][5] = wxBitmap(wxImage(_T("images/Pieces/bnB.png")));
    images[0][6] = wxBitmap(wxImage(_T("images/Pieces/bnD.png")));
    images[0][7] = wxBitmap(wxImage(_T("images/Pieces/bbB.png")));
    images[0][8] = wxBitmap(wxImage(_T("images/Pieces/bbD.png")));
    images[0][9] = wxBitmap(wxImage(_T("images/Pieces/bqB.png")));
    images[0][10] = wxBitmap(wxImage(_T("images/Pieces/bqD.png")));
    images[0][11] = wxBitmap(wxImage(_T("images/Pieces/bkB.png")));
    images[0][12] = wxBitmap(wxImage(_T("images/Pieces/bkD.png")));

    images[1][0] = wxBitmap(wxImage("images/B.jpg"));
    images[1][1] = wxBitmap(wxImage(_T("images/Pieces/wpB.png")));
    images[1][2] = wxBitmap(wxImage(_T("images/Pieces/wpD.png")));
    images[1][3] = wxBitmap(wxImage(_T("images/Pieces/wrB.png")));
    images[1][4] = wxBitmap(wxImage(_T("images/Pieces/wrD.png")));
    images[1][5] = wxBitmap(wxImage(_T("images/Pieces/wnB.png")));
    images[1][6] = wxBitmap(wxImage(_T("images/Pieces/wnD.png")));
    images[1][7] = wxBitmap(wxImage(_T("images/Pieces/wbB.png")));
    images[1][8] = wxBitmap(wxImage(_T("images/Pieces/wbD.png")));
    images[1][9] = wxBitmap(wxImage(_T("images/Pieces/wqB.png")));
    images[1][10] = wxBitmap(wxImage(_T("images/Pieces/wqD.png")));
    images[1][12] = wxBitmap(wxImage(_T("images/Pieces/wkD.png")));
    images[1][11] = wxBitmap(wxImage(_T("images/Pieces/wkB.png")));

    board[0][0] = BitmapButton1;
    board[0][1] = new wxBitmapButton(this, wxNewId(), images[0][6], wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[0][2] = new wxBitmapButton(this, wxNewId(), images[0][7], wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[0][3] = new wxBitmapButton(this, wxNewId(), images[0][10], wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[0][4] = new wxBitmapButton(this, wxNewId(), images[0][11], wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[0][5] = new wxBitmapButton(this, wxNewId(), images[0][8], wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[0][6] = new wxBitmapButton(this, wxNewId(), images[0][5], wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[0][7] = new wxBitmapButton(this, wxNewId(), images[0][4], wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);

    for(int j = 0; j < 8; j++){
        if(j%2 == 0){
            board[1][j] = new wxBitmapButton(this, wxNewId(),images[0][2] , wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
        }else{
            board[1][j] = new wxBitmapButton(this, wxNewId(),images[0][1] , wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);

        }
    }

    for(int i = 2; i < 6; i++){
        for(int j = 0; j < 8; j++){
            if((i+j)%2 == 0){
                board[i][j] = new wxBitmapButton(this, wxNewId(), images[1][0], wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
            }else{
                board[i][j] = new wxBitmapButton(this, wxNewId(), images[0][0], wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
            }
        }
    }

    for(int j = 0; j < 8; j++){
        if((j)%2 != 0){
            board[6][j] = new wxBitmapButton(this, wxNewId(), images[1][2], wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
        }else{
            board[6][j] = new wxBitmapButton(this, wxNewId(), images[1][1], wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);

        }
    }

    board[7][0] = new wxBitmapButton(this, wxNewId(), images[1][4], wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[7][1] = new wxBitmapButton(this, wxNewId(), images[1][5], wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[7][2] = new wxBitmapButton(this, wxNewId(), images[1][8], wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[7][3] = new wxBitmapButton(this, wxNewId(), images[1][9], wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[7][4] = new wxBitmapButton(this, wxNewId(), images[1][12], wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[7][5] = new wxBitmapButton(this, wxNewId(), images[1][7], wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[7][6] = new wxBitmapButton(this, wxNewId(), images[1][6], wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);
    board[7][7] = new wxBitmapButton(this, wxNewId(), images[1][3], wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator);

    for(int i = 0;i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(i + j == 0){
                j++;
            }
            GridSizer1->Add(board[i][j], 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
            Connect(board[i][j]->GetId(),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Chess2DDialog::OnBitmapButton1Click);


        }
    }

    }



}


Chess2DDialog::~Chess2DDialog(){
    //(*Destroy(Chess2DDialog)
    //*)
}

void Chess2DDialog::OnQuit(wxCommandEvent& event){
    Close();
}

void Chess2DDialog::OnAbout(wxCommandEvent& event){
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void Chess2DDialog::OnBitmapButton1Click(wxCommandEvent& event){
/*
  counter++;
  //Id of clicked bitmap button
  int nrBB = event.GetId() - 100;
  //_board.squares[nrBB/8][nrBB%8]


  if(counter%2 != 0){
    clickedSquare = _board.squares[nrBB/8][nrBB%8];
    return;
  }
  if(counter%2 == 0){



    return;
  }
*/

//_board->squares[0][0]->getButton()->SetBitmap(images[1][7]);

}
