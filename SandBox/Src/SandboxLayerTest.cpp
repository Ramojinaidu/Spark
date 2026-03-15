#include "SandboxLayerTest.h"
#include "Core/Application.h"
#include "TextEditor.h"
#include "imgui.h"
#include "imgui_internal.h"
#include <cstdint>
#include <fstream>
#include <ios>
#include <string>

TestLayer::TestLayer() : Layer("test") {

    {
		std::ifstream t;
		t.open(fileToEdit,std::ios_base::in);
		if (t.good())
		{
			std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
			editor.SetText(str);
		}
	}

}

TestLayer::~TestLayer() {}

void TestLayer::OnAttach() {}

void TestLayer::OnDetach() {}

void TestLayer::OnUpdate() {}

void TestLayer::OnEvent(Spark::Event& e) {}

void TestLayer::OnImGuiRender() {
    static bool show = true;
    static bool show_demo = true;
#if 0
    static float values[90] = {0};
    static bool set = Spark::Application::Get().GetWindow()->IsVSync();
;
    static int values_offset = 0;
    static double refresh_time = 0.0;
    auto io = ImGui::GetIO().Framerate;

    ImGuiID dock_id = ImGui::GetID("dock");

    #if 1
    if (ImGui::DockBuilderGetNode(dock_id)==nullptr) {

        ImGui::DockBuilderAddNode(dock_id,ImGuiDockNodeFlags_DockSpace);
        ImGui::DockBuilderSetNodeSize(dock_id, ImGui::GetMainViewport()->Size);
        ImGuiID dock_id_left =0;
        ImGuiID dock_id_right=0;
        ImGuiID dock_id_center=0;
        ImGuiID dock_id_main =dock_id;
        ImGui::DockBuilderSplitNode(dock_id_main, ImGuiDir_Left, 0.2f, &dock_id_left, &dock_id_main);
        ImGui::DockBuilderSplitNode(dock_id_main, ImGuiDir_Right, 0.2f, &dock_id_right, &dock_id_main);
        ImGuiID dock_id_left_top =0;
        ImGuiID dock_id_left_bottom =0;
        ImGui::DockBuilderSplitNode(dock_id_left, ImGuiDir_Up, 0.5f, &dock_id_left_top, &dock_id_left_bottom);
        ImGui::DockBuilderDockWindow("Test", dock_id_left_top);
        ImGui::DockBuilderDockWindow("Test-2", dock_id_left_bottom);
        ImGui::DockBuilderDockWindow("Test-4", dock_id_right);
        ImGui::DockBuilderFinish(dock_id_main);
    }

    ImGui::DockSpaceOverViewport(dock_id,ImGui::GetMainViewport(),ImGuiDockNodeFlags_PassthruCentralNode);
#endif
    ImGui::SetNextWindowSize(ImVec2(400,600));
    ImGui::Begin("Test");

    ImGui::Text("framerate: %f fps", io);

    ImGui::Checkbox("Demo Window", &show);
    ImGui::SameLine();
    ImGui::Checkbox("vsync", &set);
    Spark::Application::Get().GetWindow()->SetVSync(set);

    if (refresh_time == 0.0)
        refresh_time = ImGui::GetTime();
    if (refresh_time <
        ImGui::GetTime()) // Create data at fixed 60 Hz rate for the demo
    {
        values[values_offset] = ImGui::GetIO().Framerate;
        values_offset = (values_offset + 1) % IM_COUNTOF(values);
        refresh_time += 1.0f / 120.0f;
    }

    float average = 0.0f;
    for (int n = 0; n < IM_COUNTOF(values); n++)
        average += values[n];
    average /= (float)IM_COUNTOF(values);
    char overlay[32];
    sprintf(overlay, "avg %f FPS", average);
    ImGui::PlotLines("##1", values, IM_COUNTOF(values), values_offset, overlay,
                     average - 50, average + 50, ImVec2(380, 500));

    ImGui::End();

    ImGui::Begin("Test-2");
    ImGui::End();

    ImGui::Begin("Test-3");
    ImGui::End();

    ImGui::Begin("Test-4");
    ImGui::End();
    if (show) {
        ImGui::ShowDemoWindow(&show);
    }
#endif

#if 0
ImGui::ShowDemoWindow(&show_demo);
static char value[200];
static bool use_work_area = true;
static ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings;

const ImGuiViewport* viewport = ImGui::GetMainViewport();
ImGui::SetNextWindowPos(use_work_area ? viewport->WorkPos : viewport->Pos);
ImGui::SetNextWindowSize(use_work_area ? viewport->WorkSize : viewport->Size);

ImGui::Begin("test",&show,flags);

ImGui::InputText("##",value,200);
ImGui::SameLine();
ImGui::Button("Test1");
ImGui::End();
#endif


auto cpos = editor.GetCursorPosition();

ImGui::Begin("Text Editor Demo", nullptr, ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_MenuBar);
ImGui::SetWindowSize(ImVec2(800, 600), ImGuiCond_FirstUseEver);
if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Save"))
				{
					auto textToSave = editor.GetText();
					/// save text....
				}
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Edit"))
			{
				bool ro = editor.IsReadOnly();
				if (ImGui::MenuItem("Read-only mode", nullptr, &ro))
					editor.SetReadOnly(ro);
				ImGui::Separator();

				if (ImGui::MenuItem("Undo", "ALT-Backspace", nullptr, !ro && editor.CanUndo()))
					editor.Undo();
				if (ImGui::MenuItem("Redo", "Ctrl-Y", nullptr, !ro && editor.CanRedo()))
					editor.Redo();

				ImGui::Separator();

				if (ImGui::MenuItem("Copy", "Ctrl-C", nullptr, editor.HasSelection()))
					editor.Copy();
				if (ImGui::MenuItem("Cut", "Ctrl-X", nullptr, !ro && editor.HasSelection()))
					editor.Cut();
				if (ImGui::MenuItem("Delete", "Del", nullptr, !ro && editor.HasSelection()))
					editor.Delete();
				if (ImGui::MenuItem("Paste", "Ctrl-V", nullptr, !ro && ImGui::GetClipboardText() != nullptr))
					editor.Paste();

				ImGui::Separator();

				if (ImGui::MenuItem("Select all", nullptr, nullptr))
					editor.SetSelection(TextEditor::Coordinates(), TextEditor::Coordinates(editor.GetTotalLines(), 0));

				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("View"))
			{
				if (ImGui::MenuItem("Dark palette"))
					editor.SetPalette(TextEditor::GetDarkPalette());
				if (ImGui::MenuItem("Light palette"))
					editor.SetPalette(TextEditor::GetLightPalette());
				if (ImGui::MenuItem("Retro blue palette"))
					editor.SetPalette(TextEditor::GetRetroBluePalette());
				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}
ImGui::Text("%6d/%-6d %6d lines  | %s | %s | %s | %s", cpos.mLine + 1, cpos.mColumn + 1, editor.GetTotalLines(),
			editor.IsOverwrite() ? "Ovr" : "Ins",
			editor.CanUndo() ? "*" : " ",
			editor.GetLanguageDefinition().mName.c_str(), fileToEdit);
editor.Render("Texteditor");
ImGui::End();

}
