#include <gtkmm.h>
#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "windivert.h"

int main(int argc, char *argv[]) {

	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

	Gtk::Window window;
	window.set_default_size(200, 200);
	// Open the Divert device:
	HANDLE handle = WinDivertOpen(
			"outbound && "              // Outbound traffic only
			"ip && "                    // Only IPv4 supported
			"tcp.DstPort == 80 && "     // HTTP (port 80) only
			"tcp.PayloadLength > 0",    // TCP data packets only
			WINDIVERT_LAYER_NETWORK, 404, 0
			);
	if (handle == INVALID_HANDLE_VALUE)
	{
		fprintf(stderr, "error: failed to open the WinDivert device (%d)\n",
				GetLastError());
		exit(EXIT_FAILURE);
	}
	printf("OPENED WinDivert\n");

	return app->run(window);
}
