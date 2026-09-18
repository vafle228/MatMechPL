#include <iostream>
#include "../../headers/Model/ModelConnect.h"


const bool TRUE = true;
const bool FALSE = false;

ModelConnect::ModelConnect(std::fstream* stream)
{
	this->stream = stream;
}

bool ModelConnect::IsEOF()
{
	stream->seekg(pos, std::ios::beg);
	return stream->peek() == -1;
}

void ModelConnect::DeletePrev()
{
	stream->seekg(pos -= sizeof(bool), std::ios::beg);

	stream->write((char*)&TRUE, sizeof(bool));

	pos = stream->tellg();
}

void ModelConnect::AddModel(ModelAttrs attrs)
{
	stream->seekg(0, std::ios::end);

	for (auto it = attrs.begin(); it != attrs.end(); it++) 
		it->second->WriteBinary(stream);
	stream->write((char*)&FALSE, sizeof(bool));
}

void ModelConnect::ReadModel(ModelAttrs attrs)
{
	stream->seekg(pos, std::ios::beg);
	bool deleted = true;

	while (deleted && !IsEOF()) 
	{
		for (auto it = attrs.begin(); it != attrs.end(); it++)
			it->second->ReadBinary(stream);
		stream->read((char*)&deleted, sizeof(bool));

		pos = stream->tellg();
	}

	pos = stream->tellg();

	if (deleted && IsEOF()) throw std::exception();
}

void ModelConnect::UpdatePrev(ModelAttrs attrs)
{
	for (auto it = attrs.begin(); it != attrs.end(); it++)
		pos -= it->second->Sizeof();
	stream->seekg(pos -= 1, std::ios::beg);

	for (auto it = attrs.begin(); it != attrs.end(); it++)
		it->second->WriteBinary(stream);
	stream->write((char*)&FALSE, sizeof(bool));

	pos = stream->tellg();
}
