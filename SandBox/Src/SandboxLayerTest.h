#ifndef SANDBOXLAYERTEST_H
#define SANDBOXLAYERTEST_H

#include <Spark.h>

class TestLayer : public Spark::Layer {

  public:
    TestLayer();
    ~TestLayer();

    virtual void OnAttach() override;
    virtual void OnDetach() override;
    virtual void OnUpdate() override;
    virtual void OnImGuiRender() override;
    virtual void OnEvent(Spark::Event& e) override;
};

#endif
