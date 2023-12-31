// generated by Fast Light User Interface Designer (fluid) version 1.0305

#ifndef GuiFluidAutoGen_h
#define GuiFluidAutoGen_h
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
extern Fl_Double_Window *g_Window;
#include <FL/Fl_Wizard.H>
extern Fl_Wizard *g_Wizard;
#include <FL/Fl_Group.H>
extern Fl_Group *g_PageSettings;
#include <FL/Fl_Text_Display.H>
extern Fl_Text_Display *g_Settings_TextGreetings;
#include <FL/Fl_Input.H>
extern Fl_Input *g_Settings_InputInstallDirectory;
#include <FL/Fl_Button.H>
extern Fl_Button *g_Settings_ButtonBrowseInstallDirectory;
#include <FL/Fl_Box.H>
#include <FL/Fl_Check_Button.H>
extern Fl_Check_Button *g_Settings_CheckAdvancedSettings;
extern Fl_Check_Button *g_Settings_CheckCustomVersion;
extern Fl_Check_Button *g_Settings_CheckSkipSelfUpdate;
extern Fl_Check_Button *g_Settings_CheckSkipConfigDownload;
extern Fl_Check_Button *g_Settings_CheckForceScan;
extern Fl_Check_Button *g_Settings_CheckBitwiseExact;
extern Fl_Check_Button *g_Settings_CheckNoMultipartByteranges;
#include <FL/Fl_Progress.H>
extern Fl_Progress *g_Settings_ProgressScanning;
extern Fl_Button *g_Settings_ButtonNext;
extern Fl_Button *g_Settings_ButtonReset;
extern Fl_Button *g_Settings_ButtonRestartNewDir;
extern Fl_Group *g_PageVersion;
#include <FL/Fl_Output.H>
extern Fl_Output *g_Version_OutputLastInstalledVersion;
#include <FL/Fl_Tree.H>
extern Fl_Tree *g_Version_TreeVersions;
extern Fl_Input *g_Version_InputCustomManifestUrl;
extern Fl_Box *g_Version_TextCustomManifestMessage;
extern Fl_Output *g_Version_OutputCurrentSize;
extern Fl_Output *g_Version_OutputFinalSize;
extern Fl_Output *g_Version_OutputAddedSize;
extern Fl_Output *g_Version_OutputRemovedSize;
extern Fl_Output *g_Version_OutputDownloadSize;
extern Fl_Button *g_Version_ButtonRefreshInfo;
extern Fl_Progress *g_Version_ProgressDownloadManifests;
extern Fl_Button *g_Version_ButtonNext;
extern Fl_Button *g_Version_ButtonBack;
#include <FL/Fl_Choice.H>
extern Fl_Choice *g_Version_ChoiceMirror;
extern Fl_Group *g_PageConfirm;
extern Fl_Text_Display *g_Confirm_TextReadyToInstall;
extern Fl_Output *g_Confirm_OutputInstallDirectory;
extern Fl_Output *g_Confirm_OutputLastInstalledVersion;
extern Fl_Output *g_Confirm_OutputVersionToInstall;
extern Fl_Output *g_Confirm_OutputCurrentSize;
extern Fl_Output *g_Confirm_OutputFinalSize;
extern Fl_Output *g_Confirm_OutputAddedSize;
extern Fl_Output *g_Confirm_OutputRemovedSize;
extern Fl_Output *g_Confirm_OutputDownloadSize;
extern Fl_Button *g_Confirm_ButtonStart;
extern Fl_Button *g_Confirm_ButtonBack;
extern Fl_Group *g_PageInstall;
extern Fl_Text_Display *g_Install_TextInstalling;
extern Fl_Progress *g_Install_ProgressDownload;
extern Fl_Box *g_Install_OutputRemainDownload;
extern Fl_Progress *g_Install_ProgressVerify;
extern Fl_Progress *g_Install_ProgressRepack;
extern Fl_Progress *g_Install_ProgressFinalize;
extern Fl_Text_Display *g_Install_TextFinishedInstall;
extern Fl_Button *g_Install_ButtonClose;
extern Fl_Button *g_Install_ButtonCancel;
extern Fl_Button *g_Install_ButtonRestoreCfg;
extern Fl_Text_Display *g_Install_TextAdditional;
extern Fl_Button *g_Install_ButtonCreateShortcut;
void FluidAllGui();
void WizardGoNext();
void WizardGoPrev();
extern Fl_Double_Window *g_HelpWindow;
extern Fl_Text_Display *g_Help_TextParameters;
Fl_Double_Window* FluidGuiHelp();
#endif
