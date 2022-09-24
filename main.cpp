#include <iostream>
#include <cmath>
#include "TApplication.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TRootCanvas.h"
#include "TMath.h"

int main(int argc, char **argv) {
    TApplication app("app", &argc, argv);
    TCanvas* c = new TCanvas("c", "Some Test", 0, 0, 800, 600);
    TF1 *f1 = new TF1("f1", "sin(x)", -25, 25);

    f1->SetLineColor(kBlue+1);
    f1->SetLineWidth(3);
    f1->SetTitle("My graph;x;x sin(x)");
    f1->Draw();
    c->Modified(); c->Update();

    TRootCanvas *rc = (TRootCanvas *)c->GetCanvasImp();
    rc->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");

    app.Run();
    return 0;
}
