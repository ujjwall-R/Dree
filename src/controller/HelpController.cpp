#include "HelpController.h"

HelpController::HelpController(AboutDreeI* aboutInterface) { this->aboutInterface = aboutInterface; }

void HelpController::help() { aboutInterface->print_help_instructions(); }
