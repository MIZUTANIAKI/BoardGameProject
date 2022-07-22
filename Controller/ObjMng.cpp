#include <vector>
#include <stdio.h>
#include <map>
#include <string>
#include <DxLib.h>
#include "ObjMng.h"

ObjMng* ObjMng::sInstance = nullptr;

void ObjMng::DrawNaw(void)
{
	//�ʏ함�����ׂĕ`���A�K���X�Ȃǂ̓����������̂�`�悷��
	//����`��
	
	//MV1SetSemiTransDrawMode(DX_SEMITRANSDRAWMODE_ALWAYS);
	for (auto dQue : drawList_)
	{
		DxLib::MV1DrawModel(dQue);
	}
	
	//MV1SetSemiTransDrawMode(DX_SEMITRANSDRAWMODE_SEMITRANS_ONLY);
	
	////������̂�`��
	//DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
	//
	//for (auto dQue : drawListnex_)
	//{
	//	DxLib::MV1DrawModel(dQue);
	//}

	//DxLib::SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void ObjMng::ReSetD(void)
{
	drawList_.clear();
	//drawListnex_.clear();
}

void ObjMng::Setobjpos(int mv1,VECTOR pos)
{
	DxLib::MV1SetPosition(GetModelHandle(mv1), pos);
}

void ObjMng::ObjDraw(int mv1)
{
	drawList_.emplace_back(GetModelHandle(mv1));
}

void ObjMng::SetRotation(int mv1, float moveangle)
{
	DxLib::MV1SetRotationXYZ(GetModelHandle(mv1), VGet(0.0f, moveangle / 180.0f * DX_PI_F, 0.0f));
}

void ObjMng::SetScale(int mv1, VECTOR scale)
{
	MV1SetScale(GetModelHandle(mv1), scale);
}

int ObjMng::LoadModel(std::string fileName)
{
	std::string tstr= "MV1Date/";
	tstr += fileName;
	mv1List_.try_emplace(static_cast<int>(mv1List_.size()),MV1LoadModel(tstr.c_str()));

	return static_cast<int>(mv1List_.size()) - 1;
}

void ObjMng::DeleteModel(int mv1)
{

	MV1DeleteModel(GetModelHandle(mv1));
	mv1List_.erase(mv1);
}

void ObjMng::ReSetModelDate(void)
{
	for (const auto& modelHandle : mv1List_)
	{
		if (modelHandle.second != -1)
		{
			MV1DeleteModel(modelHandle.second);
		}
	}
	mv1List_.clear();
}

int ObjMng::CopyModel(int mv1)
{
	mv1List_.try_emplace(static_cast<int>(mv1List_.size()),MV1DuplicateModel(GetModelHandle(mv1)));
	return static_cast<int>(mv1List_.size()) - 1;
}

int ObjMng::GetModelHandle(int mv1)
{
	if (mv1List_.size() <= mv1)
	{
		return -1;
	}

	if (mv1 < 0)
	{
		return -1;
	}
	if (auto iter = mv1List_.find(mv1); iter != end(mv1List_))
	{
		return iter->second;
	}
	else
	{
		return -1;
	}
}

ObjMng::ObjMng()
{
}

ObjMng::~ObjMng()
{
	ReSetModelDate();
	ReSetD();
}