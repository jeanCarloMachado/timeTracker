#include "Message.h"

Message::Message()
{
}

string Message::show(string _id){
	string outputMessage;

	if(_id=="hello")
		outputMessage="Bem Vindo ao sistema TimeTracker! use --help para ajuda";
	else if(_id=="errorParam")
		outputMessage="Passe os parametros corretamente.";
	else if(_id=="notFound")
		outputMessage="Comando não encontrado.";
	else
		outputMessage="Nenhuma Entrada correspondente.";

	return outputMessage;
}