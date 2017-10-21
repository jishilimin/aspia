//
// PROJECT:         Aspia Remote Desktop
// FILE:            ui/system_info/save_report_dialog.h
// LICENSE:         Mozilla Public License Version 2.0
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_UI__SYSTEM_INFO__SAVE_REPORT_DIALOG_H
#define _ASPIA_UI__SYSTEM_INFO__SAVE_REPORT_DIALOG_H

#include "base/macros.h"
#include "ui/resource.h"

#include <atlbase.h>
#include <atlapp.h>
#include <atlwin.h>
#include <atlframe.h>
#include <atlmisc.h>

namespace aspia {

class SaveReportDialog :
    public CDialogImpl<SaveReportDialog>,
    public CDialogResize<SaveReportDialog>
{
public:
    enum { IDD = IDD_SAVE_REPORT };

    SaveReportDialog() = default;
    ~SaveReportDialog() = default;

private:
    BEGIN_MSG_MAP(SaveReportDialog)
        MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
        MESSAGE_HANDLER(WM_CLOSE, OnClose)

        COMMAND_ID_HANDLER(IDOK, OnSaveButton)
        COMMAND_ID_HANDLER(IDCANCEL, OnCancelButton)

        CHAIN_MSG_MAP(CDialogResize<SaveReportDialog>)
    END_MSG_MAP()

    BEGIN_DLGRESIZE_MAP(SaveReportDialog)
        DLGRESIZE_CONTROL(IDC_CATEGORY_TREE, DLSZ_SIZE_X | DLSZ_SIZE_Y)
        DLGRESIZE_CONTROL(IDC_SELECT_ALL, DLSZ_MOVE_Y)
        DLGRESIZE_CONTROL(IDC_UNSELECT_ALL, DLSZ_MOVE_Y)
        DLGRESIZE_CONTROL(IDOK, DLSZ_MOVE_X | DLSZ_MOVE_Y)
        DLGRESIZE_CONTROL(IDCANCEL, DLSZ_MOVE_X | DLSZ_MOVE_Y)
    END_DLGRESIZE_MAP()

    LRESULT OnInitDialog(UINT message, WPARAM wparam, LPARAM lparam, BOOL& handled);
    LRESULT OnClose(UINT message, WPARAM wparam, LPARAM lparam, BOOL& handled);
    LRESULT OnSaveButton(WORD notify_code, WORD ctrl_id, HWND ctrl, BOOL& handled);
    LRESULT OnCancelButton(WORD notify_code, WORD ctrl_id, HWND ctrl, BOOL& handled);

    CIcon small_icon_;
    CIcon big_icon_;
    CIcon select_all_icon_;
    CIcon unselect_all_icon_;

    DISALLOW_COPY_AND_ASSIGN(SaveReportDialog);
};

} // namespace aspia

#endif // _ASPIA_UI__SYSTEM_INFO__SAVE_REPORT_DIALOG_H