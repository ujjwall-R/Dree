#include "../view/AboutDreeI.h"
#include "HelpControllerI.h"

class HelpController : public HelpControllerI {

   private:
    AboutDreeI* aboutInterface;

   public:
    explicit HelpController(AboutDreeI* aboutInterface);

    void help() override;
};
