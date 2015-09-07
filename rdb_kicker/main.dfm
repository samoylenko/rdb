object frmMain: TfrmMain
  Left = 192
  Top = 114
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'rdb_kicker'
  ClientHeight = 86
  ClientWidth = 147
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 39
    Height = 13
    Caption = 'User ID:'
  end
  object Label2: TLabel
    Left = 104
    Top = 8
    Width = 29
    Height = 13
    Caption = '(c) pm'
  end
  object edtUID: TEdit
    Left = 8
    Top = 24
    Width = 129
    Height = 21
    TabOrder = 0
    Text = '1'
  end
  object btnKick: TButton
    Left = 8
    Top = 48
    Width = 129
    Height = 25
    Caption = 'Kick'
    Default = True
    TabOrder = 1
    OnClick = btnKickClick
  end
  object IBDatabase1: TIBDatabase
    Connected = True
    DatabaseName = 'RKB-SERVER:f:\egeo_db\chat.gdb'
    Params.Strings = (
      'user_name=MAIN'
      'password=main')
    LoginPrompt = False
    DefaultTransaction = IBTransaction1
    IdleTimer = 0
    SQLDialect = 3
    TraceFlags = []
    Left = 24
    Top = 8
  end
  object IBTransaction1: TIBTransaction
    Active = False
    DefaultDatabase = IBDatabase1
    AutoStopAction = saNone
    Left = 56
    Top = 8
  end
  object IBQuery1: TIBQuery
    Database = IBDatabase1
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'CREATE PROCEDURE "KICK_USER"'
      '('
      'ID_USER INTEGER'
      ')'
      'AS'
      ''
      'begin'
      ' post_event '#39'EXIT_'#39'||ID_USER;'
      ' suspend;'
      'end;'
      '')
    Left = 32
    Top = 40
  end
  object IBQuery2: TIBQuery
    Database = IBDatabase1
    Transaction = IBTransaction1
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'drop procedure KICK_USER;')
    Left = 104
    Top = 48
  end
  object IBStoredProc1: TIBStoredProc
    Database = IBDatabase1
    Transaction = IBTransaction1
    StoredProcName = 'KICK_USER'
    Left = 72
    Top = 48
    ParamData = <
      item
        DataType = ftInteger
        Name = 'ID_USER'
        ParamType = ptInput
        Value = '1'
      end>
  end
end
