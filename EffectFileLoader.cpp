#include "Nel.h"

namespace nel {
	//�p�[�e�B�N���t�@�C���̑���N���X----------------------------------------------------------------------------------------------------------

	//�t�@�C������p�[�e�B�N���̃p�����[�^�l��ǂݍ��݂܂��i.particle�`���j
	void CParticleFile::ReadParticleFile(wstring filename) {
		ifstream ifs(GetExePath() + L"../effect/" + filename);
		string buf;

		while (ifs && getline(ifs, buf) && buf != "eop") {
			//������������������Ă����󂯎M
			vector<string> result;

			//������̕���
			Split(buf, ':', result);

			//�p�����[�^�l�̓ǂݏo��
			if (result[0] == "Name")					Name						= StringToWString(result[1]);
			if (result[0] == "TextureName")				TextureName					= StringToWString(result[1]);
			if (result[0] == "ModelName")				ModelName					= StringToWString(result[1]);
			if (result[0] == "InitScale")				InitScale					= StringToCVector(result[1]);
			if (result[0] == "InitScaleRange")			InitScaleRange				= StringToCVector(result[1]);
			if (result[0] == "EndScale")				EndScale					= StringToCVector(result[1]);
			if (result[0] == "InitColor")				InitColor					= StringToCColor(result[1]);
			if (result[0] == "InitColorRange")			InitColorRange				= StringToCColor(result[1]);
			if (result[0] == "EndColor")				EndColor					= StringToCColor(result[1]);
			if (result[0] == "InitSpecularColor")		InitSpecularColor			= StringToCColor(result[1]);
			if (result[0] == "InitSpecularColorRange")	InitSpecularColorRange		= StringToCColor(result[1]);
			if (result[0] == "EndSpecularColor")		EndColor					= StringToCColor(result[1]);
			if (result[0] == "InitEmissiveColor")		InitEmissiveColor			= StringToCColor(result[1]);
			if (result[0] == "InitEmissiveColorRange")	InitEmissiveColorRange		= StringToCColor(result[1]);
			if (result[0] == "EndEmissiveColor")		EndEmissiveColor			= StringToCColor(result[1]);
			if (result[0] == "InitRimColor")			InitRimColor				= StringToCColor(result[1]);
			if (result[0] == "InitRimColorRange")		InitRimColorRange			= StringToCColor(result[1]);
			if (result[0] == "EndRimColor")				EndRimColor					= StringToCColor(result[1]);
			if (result[0] == "PositionRange")			PositionRange				= StringToCVector(result[1]);
			if (result[0] == "InitVelocity")			InitVelocity				= StringToCVector(result[1]);
			if (result[0] == "InitVelocityRange")		InitVelocityRange			= StringToCVector(result[1]);
			if (result[0] == "Velocity")				Velocity					= StringToCVector(result[1]);
			if (result[0] == "VelocityRange")			VelocityRange				= StringToCVector(result[1]);
			if (result[0] == "InitRotation")			InitRotation				= StringToCQuaternion(result[1]);
			if (result[0] == "InitRotationRange")		InitRotationRange			= StringToCQuaternion(result[1]);
			if (result[0] == "Rotation")				Rotation					= StringToCQuaternion(result[1]);
			if (result[0] == "RotationRange")			RotationRange				= StringToCQuaternion(result[1]);
			if (result[0] == "UseGravity")				UseGravity					= StringToBool(result[1]);
			if (result[0] == "Gravity")					Gravity						= StringToFloat(result[1]);
			if (result[0] == "LifeTime")				LifeTime					= (unsigned int)StringToInt(result[1]);
			if (result[0] == "LifeTimeRange")			LifeTimeRange				= (unsigned int)StringToInt(result[1]);
			if (result[0] == "Billboard")				Billboard					= StringToBool(result[1]);
			if (result[0] == "ShadowCasting")			ShadowCasting				= StringToBool(result[1]);
			if (result[0] == "ShadowCasted")			ShadowCasted				= StringToBool(result[1]);
		}

		//�ω��ʂ����߂�
		Movement();
	}

	//�p�[�e�B�N���t�@�C�����쐬���܂�
	//�쐬�ꏊ�ɓ������O�̃t�@�C��������ꍇ�A�쐬����܂���
	void CreateParticleFile(wstring filename){
		ofstream ofs(GetExePath() + L"../effect/" + filename + L".particle", ios::out | ios::_Noreplace);

		if (ofs) {
			ofs << "Name:"						<< TWStringToString(filename) << endl
				<< "TextureName:"				<< endl
				<< "ModelName:"					<< endl
				<< "InitScale:,,"				<< endl
				<< "InitScaleRange:,,"			<< endl
				<< "EndScale:,,"				<< endl
				<< "InitColor:,,,"				<< endl
				<< "InitColorRange:,,,"			<< endl
				<< "EndColor:,,,"				<< endl
				<< "InitSpecularColor:,,,"		<< endl
				<< "InitSpecularColorRange:,,," << endl
				<< "EndSpecularColor:,,,"		<< endl
				<< "InitEmissiveColor:,,,"		<< endl
				<< "InitEmissiveColorRange:,,," << endl
				<< "EndEmissiveColor:,,,"		<< endl
				<< "InitRimColor:,,,"			<< endl
				<< "InitRimColorRange:,,,"		<< endl
				<< "EndRimColor:,,,"			<< endl
				<< "PositionRange:,,"			<< endl
				<< "InitVelocity:,,"			<< endl
				<< "InitVelocityRange:,,"		<< endl
				<< "Velocity:,,"				<< endl
				<< "VelocityRange:,,"			<< endl
				<< "InitRotation:,,,"			<< endl
				<< "InitRotationRange:,,,"		<< endl
				<< "Rotation:,,,"				<< endl
				<< "RotationRange:,,,"			<< endl
				<< "UseGravity:"				<< endl
				<< "Gravity:"					<< endl
				<< "LifeTime:"					<< endl
				<< "LifeTimeRange:"				<< endl
				<< "Billboard:"					<< "true" << endl
				<< "ShadowCasting:"				<< "true" << endl
				<< "ShadowCasted:"				<< "true" << endl
				<< "eop" << endl
				<< endl
				<< endl
				<< "eof" << endl;
		}
	}


	//�G�~�b�^�t�@�C���̑���N���X--------------------------------------------------------------------------------------------------------------

	//�t�@�C������G�~�b�^�̃p�����[�^�l��ǂݍ��݂܂��i.emitter�`���j
	void CEmitterFile::ReadEmitterFile(wstring filename) {
		ifstream ifs(GetExePath() + L"../effect/" + filename);
		string buf;

		while (ifs && getline(ifs, buf) && buf != "eoe") {
			//������������������Ă����󂯎M
			vector<string> result;

			//������̕���
			Split(buf, ':', result);

			//�p�����[�^�l�̓ǂݏo��
			if (result[0] == "Name")					Name				= StringToWString(result[1]);
			if (result[0] == "PositionRange")			PositionRange		= StringToCVector(result[1]);
			if (result[0] == "InitVelocity")			InitVelocity		= StringToCVector(result[1]);
			if (result[0] == "InitVelocityRange")		InitVelocityRange	= StringToCVector(result[1]);
			if (result[0] == "Velocity")				Velocity			= StringToCVector(result[1]);
			if (result[0] == "VelocityRange")			VelocityRange		= StringToCVector(result[1]);
			if (result[0] == "InitRotation")			InitRotation		= StringToCQuaternion(result[1]);
			if (result[0] == "InitRotationRange")		InitRotationRange	= StringToCQuaternion(result[1]);
			if (result[0] == "Rotation")				Rotation			= StringToCQuaternion(result[1]);
			if (result[0] == "RotationRange")			RotationRange		= StringToCQuaternion(result[1]);
			if (result[0] == "LifeTime")				LifeTime			= (unsigned int)StringToInt(result[1]);
			if (result[0] == "LifeTimeRange")			LifeTimeRange		= (unsigned int)StringToInt(result[1]);
			if (result[0] == "Emitter") {
				//�ĕ�����������������Ă����󂯎M
				vector<string> value;

				//������̍ĕ���
				Split(result[1], ',', value);

				EGenerationList.push_back(StringToWString(value[0]));
				EInterval.push_back((unsigned int)StringToInt(value[1]));
				EProduction.push_back((unsigned int)StringToInt(value[2]));
			}
			if (result[0] == "Particle") {
				//�ĕ�����������������Ă����󂯎M
				vector<string> value;

				//������̍ĕ���
				Split(result[1], ',', value);

				PGenerationList.push_back(StringToWString(value[0]));
				PInterval.push_back((unsigned int)StringToInt(value[1]));
				PProduction.push_back((unsigned int)StringToInt(value[2]));
			}
		}

		//�ω��ʂ����߂�
		Movement();
	}

	//�G�~�b�^�t�@�C�����쐬���܂�
	//�쐬�ꏊ�ɓ������O�̃t�@�C��������ꍇ�A�쐬����܂���
	void CreateEmitterFile(wstring filename){
		ofstream ofs(GetExePath() + L"../effect/" + filename + L".emitter", ios::out | ios::_Noreplace);

		if (ofs) {
			ofs << "Name:" << TWStringToString(filename) << endl
				<< "PositionRange:0, 0, 0" << endl
				<< "InitVelocity:0, 0, 0" << endl
				<< "InitVelocityRange:0, 0, 0" << endl
				<< "Velocity:0, 0, 0" << endl
				<< "VelocityRange:0, 0, 0" << endl
				<< "InitRotation:0, 0, 0, 0" << endl
				<< "InitRotationRange:0, 0, 0, 0" << endl
				<< "Rotation:0, 0, 0, 0" << endl
				<< "RotationRange:0, 0, 0, 0" << endl
				<< "LifeTime:1" << endl
				<< "LifeTimeRange:0" << endl
				<< "//Emitter:.emitter, 1, 1" << endl
				<< "//Particle:.particle, 1, 1" << endl
				<< "eoe" << endl
				<< endl
				<< endl
				<< "eof" << endl;
		}
	}

}
