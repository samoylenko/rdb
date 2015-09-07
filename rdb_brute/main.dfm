object Form1: TForm1
  Left = 245
  Top = 151
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'rdb_brute (c) pm'
  ClientHeight = 248
  ClientWidth = 248
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 11
    Width = 49
    Height = 13
    Alignment = taRightJustify
    Caption = 'Database:'
    Layout = tlCenter
  end
  object Label2: TLabel
    Left = 40
    Top = 35
    Width = 25
    Height = 13
    Alignment = taRightJustify
    Caption = 'User:'
    Layout = tlCenter
  end
  object Label3: TLabel
    Left = 16
    Top = 59
    Width = 49
    Height = 13
    Alignment = taRightJustify
    Caption = 'Password:'
    Layout = tlCenter
  end
  object user: TEdit
    Left = 72
    Top = 32
    Width = 169
    Height = 21
    TabOrder = 1
  end
  object pass: TEdit
    Left = 72
    Top = 56
    Width = 169
    Height = 21
    TabOrder = 2
  end
  object btnStart: TButton
    Left = 8
    Top = 88
    Width = 113
    Height = 25
    Caption = 'Start'
    Default = True
    TabOrder = 3
    OnClick = btnStartClick
  end
  object Log: TMemo
    Left = 8
    Top = 120
    Width = 233
    Height = 89
    Lines.Strings = (
      'Log'
      '-----------------')
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 4
  end
  object btnStop: TButton
    Left = 128
    Top = 88
    Width = 113
    Height = 25
    Caption = 'Stop'
    TabOrder = 5
    OnClick = btnStopClick
  end
  object btnClose: TButton
    Left = 8
    Top = 216
    Width = 233
    Height = 25
    Cancel = True
    Caption = 'Close'
    TabOrder = 6
    OnClick = btnCloseClick
  end
  object db: TComboBox
    Left = 72
    Top = 8
    Width = 169
    Height = 21
    ItemHeight = 13
    TabOrder = 0
    Text = 'rkb-rostik:d:\db\rdb_chat.gdb'
    Items.Strings = (
      'rkb-server:f:\egeo_db\rdb_chat.gdb'
      'rkb-rostik:d:\db\rdb_chat.gdb'
      'C:\Program Files\Borland\InterBase\bin\CHAT.GDB')
  end
  object IBDb1: TIBDatabase
    DatabaseName = 'C:\Program Files\Borland\InterBase\bin\CHAT.GDB'
    Params.Strings = (
      'user_name=MAIN'
      'password=main'
      'lc_ctype=WIN1251')
    LoginPrompt = False
    DefaultTransaction = IBTa1
    IdleTimer = 0
    SQLDialect = 3
    TraceFlags = []
    Left = 120
    Top = 144
  end
  object IBTa1: TIBTransaction
    Active = False
    DefaultDatabase = IBDb1
    AutoStopAction = saNone
    Left = 152
    Top = 144
  end
  object IBSp1: TIBStoredProc
    Database = IBDb1
    Transaction = IBTa1
    StoredProcName = 'LOGIN'
    Left = 184
    Top = 144
    ParamData = <
      item
        DataType = ftInteger
        Name = 'ID_USER'
        ParamType = ptOutput
      end
      item
        DataType = ftString
        Name = 'PASW_USER'
        ParamType = ptInput
      end
      item
        DataType = ftString
        Name = 'NAME_USER'
        ParamType = ptInput
      end>
  end
end
