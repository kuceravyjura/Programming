#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

#include "include/cpp-httplib/httplib.h"
#include "include/nlohmann/json.hpp"

using json = nlohmann::json;
using namespace httplib;

std::ofstream logger("output.log");

json get_config();


void save_config(json config);


std::string gen_webhook_page();



void webhooks_get(const Request& req, Response& res);
void webhooks_post(const Request& req, Response& res);


void yandex_hook(const Request& req, Response& res);


int main()
{
	Server srv;

	srv.Get("/webhooks", webhooks_get);
	srv.Post("/webhooks", webhooks_post);
	srv.Post("/yandex_hook", yandex_hook);

	std::cout << "Сервер успешно запустился!\n"<< "Сервер откыт по адресу localhost:1234\n\n"<< "Откройте http://localhost:1234/webhooks в веб-браузере, "<< "чтобы получить доступ к панели управления веб-хуками.\n"<< std::endl;

	srv.listen("localhost", 1234);
}
