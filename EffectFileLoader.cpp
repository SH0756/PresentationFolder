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
			if (result[0] == "Name")					PName						= StringToWString(result[1]);
			if (result[0] == "TextureName")				PTextureName				= StringToWString(result[1]);
			if (result[0] == "ModelName")				PModelName					= StringToWString(result[1]);
			if (result[0] == "InitScale")				PInitScale					= StringToCVector(result[1]);
			if (result[0] == "InitScaleRange")			PInitScaleRange				= StringToCVector(result[1]);
			if (result[0] == "EndScale")				PEndScale					= StringToCVector(result[1]);
			if (result[0] == "InitColor")				PInitColor					= StringToCColor(result[1]);
			if (result[0] == "InitColorRange")			PInitColorRange				= StringToCColor(result[1]);
			if (result[0] == "EndColor")				PEndColor					= StringToCColor(result[1]);
			if (result[0] == "InitSpecularColor")		PInitSpecularColor			= StringToCColor(result[1]);
			if (result[0] == "InitSpecularColorRange")	PInitSpecularColorRange		= StringToCColor(result[1]);
			if (result[0] == "EndSpecularColor")		PEndColor					= StringToCColor(result[1]);
			if (result[0] == "InitEmissiveColor")		PInitEmissiveColor			= StringToCColor(result[1]);
			if (result[0] == "InitEmissiveColorRange")	PInitEmissiveColorRange		= StringToCColor(result[1]);
			if (result[0] == "EndEmissiveColor")		PEndEmissiveColor			= StringToCColor(result[1]);
			if (result[0] == "InitRimColor")			PInitRimColor				= StringToCColor(result[1]);
			if (result[0] == "InitRimColorRange")		PInitRimColorRange			= StringToCColor(result[1]);
			if (result[0] == "EndRimColor")				PEndRimColor				= StringToCColor(result[1]);
			if (result[0] == "PositionRange")			PPositionRange				= StringToCVector(result[1]);
			if (result[0] == "InitVelocity")			PInitVelocity				= StringToCVector(result[1]);
			if (result[0] == "InitVelocityRange")		PInitVelocityRange			= StringToCVector(result[1]);
			if (result[0] == "Velocity")				PVelocity					= StringToCVector(result[1]);
			if (result[0] == "VelocityRange")			PVelocityRange				= StringToCVector(result[1]);
			if (result[0] == "InitRotation")			PInitRotation				= StringToCQuaternion(result[1]);
			if (result[0] == "InitRotationRange")		PInitRotationRange			= StringToCQuaternion(result[1]);
			if (result[0] == "Rotation")				PRotation					= StringToCQuaternion(result[1]);
			if (result[0] == "RotationRange")			PRotationRange				= StringToCQuaternion(result[1]);
			if (result[0] == "UseGravity")				PUseGravity					= StringToBool(result[1]);
			if (result[0] == "Gravity")					PGravity					= StringToFloat(result[1]);
			if (result[0] == "LifeTime")				PLifeTime					= (unsigned int)StringToInt(result[1]);
			if (result[0] == "LifeTimeRange")			PLifeTimeRange				= (unsigned int)StringToInt(result[1]);
			if (result[0] == "Billboard")				PBillboard					= StringToBool(result[1]);
			if (result[0] == "ShadowCasting")			PShadowCasting				= StringToBool(result[1]);
			if (result[0] == "ShadowCasted")			PShadowCasted				= StringToBool(result[1]);
		}
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
			if (result[0] == "Name")					EName				= StringToWString(result[1]);
			if (result[0] == "PositionRange")			EPositionRange		= StringToCVector(result[1]);
			if (result[0] == "InitVelocity")			EInitVelocity		= StringToCVector(result[1]);
			if (result[0] == "InitVelocityRange")		EInitVelocityRange	= StringToCVector(result[1]);
			if (result[0] == "Velocity")				EVelocity			= StringToCVector(result[1]);
			if (result[0] == "VelocityRange")			EVelocityRange		= StringToCVector(result[1]);
			if (result[0] == "InitRotation")			EInitRotation		= StringToCQuaternion(result[1]);
			if (result[0] == "InitRotationRange")		EInitRotationRange	= StringToCQuaternion(result[1]);
			if (result[0] == "Rotation")				ERotation			= StringToCQuaternion(result[1]);
			if (result[0] == "RotationRange")			ERotationRange		= StringToCQuaternion(result[1]);
			if (result[0] == "LifeTime")				ELifeTime			= (unsigned int)StringToInt(result[1]);
			if (result[0] == "LifeTimeRange")			ELifeTimeRange		= (unsigned int)StringToInt(result[1]);
			if (result[0] == "Emitter") {
				//�ĕ�����������������Ă����󂯎M
				vector<string> value;

				//������̍ĕ���
				Split(result[1], ',', value);

				EEGenerationList.push_back(StringToWString(value[0]));
				EEInterval.push_back((unsigned int)StringToInt(value[1]));
				EEProduction.push_back((unsigned int)StringToInt(value[2]));
			}
			if (result[0] == "Particle") {
				//�ĕ�����������������Ă����󂯎M
				vector<string> value;

				//������̍ĕ���
				Split(result[1], ',', value);

				EPGenerationList.push_back(StringToWString(value[0]));
				EPInterval.push_back((unsigned int)StringToInt(value[1]));
				EPProduction.push_back((unsigned int)StringToInt(value[2]));
			}
		}
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
