#include "Nel.h"

namespace nel {
	//�p�[�e�B�N���t�@�C���̑���----------------------------------------------------------------------------------------------------------

	//�t�@�C������p�[�e�B�N���̃p�����[�^�l��ǂݍ��݂܂��i.particle�`���j
	void CParticleFile::ReadParticleFile(wstring filename, ParticleParameter& param) {
		ifstream ifs(GetExePath() + L"../effect/" + filename);
		string buf;

		while (ifs && getline(ifs, buf) && buf != "eop") {

			vector<string> result;

			//������̕���
			Split(buf, ':', result);

			//�p�����[�^�l�̓ǂݏo��
			if (result[0] == "Name")					param.Name						= StringToWString(result[1]);
			if (result[0] == "TextureName")				param.TextureName				= StringToWString(result[1]);
			if (result[0] == "ModelName")				param.ModelName					= StringToWString(result[1]);
			if (result[0] == "InitScale")				param.InitScale					= StringToCVector(result[1]);
			if (result[0] == "InitScaleRange")			param.InitScaleRange			= StringToCVector(result[1]);
			if (result[0] == "EndScale")				param.EndScale					= StringToCVector(result[1]);
			if (result[0] == "InitColor")				param.InitColor					= StringToCColor(result[1]);
			if (result[0] == "InitColorRange")			param.InitColorRange			= StringToCColor(result[1]);
			if (result[0] == "EndColor")				param.EndColor					= StringToCColor(result[1]);
			if (result[0] == "InitEmissiveColor")		param.InitEmissiveColor			= StringToCColor(result[1]);
			if (result[0] == "InitEmissiveColorRange")	param.InitEmissiveColorRange	= StringToCColor(result[1]);
			if (result[0] == "EndEmissiveColor")		param.EndEmissiveColor			= StringToCColor(result[1]);
			if (result[0] == "PositionRange")			param.PositionRange				= StringToCVector(result[1]);
			if (result[0] == "InitVelocity")			param.InitVelocity				= StringToCVector(result[1]);
			if (result[0] == "InitVelocityRange")		param.InitVelocityRange			= StringToCVector(result[1]);
			if (result[0] == "Velocity")				param.Velocity					= StringToCVector(result[1]);
			if (result[0] == "VelocityRange")			param.VelocityRange				= StringToCVector(result[1]);
			if (result[0] == "InitRotation")			param.InitRotation				= StringToCQuaternion(result[1]);
			if (result[0] == "InitRotationRange")		param.InitRotationRange			= StringToCQuaternion(result[1]);
			if (result[0] == "Rotation")				param.Rotation					= StringToCQuaternion(result[1]);
			if (result[0] == "RotationRange")			param.RotationRange				= StringToCQuaternion(result[1]);
			if (result[0] == "UseGravity")				param.UseGravity				= StringToBool(result[1]);
			if (result[0] == "Gravity")					param.Gravity					= StringToFloat(result[1]);
			if (result[0] == "LifeTime")				param.LifeTime					= (unsigned int)StringToInt(result[1]);
			if (result[0] == "LifeTimeRange")			param.LifeTimeRange				= (unsigned int)StringToInt(result[1]);
			if (result[0] == "Billboard")				param.Billboard					= StringToBool(result[1]);
		}
	}

	//�p�[�e�B�N���t�@�C�����쐬���܂�
	//�쐬�ꏊ�ɓ������O�̃t�@�C��������ꍇ�A�쐬����܂���
	void CreateParticleFile(wstring filename){
		ofstream ofs(GetExePath() + L"../effect/" + filename + L".particle", ios::out | ios::_Noreplace);

		if (ofs) {
			ofs << "Name:" << TWStringToString(filename) << endl
				<< "TextureName:"				<< endl
				<< "ModelName:"					<< endl
				<< "InitScale:,,"				<< endl
				<< "InitScaleRange:,,"			<< endl
				<< "EndScale:,,"				<< endl
				<< "Scale:,,"					<< endl
				<< "InitColor:,,,"				<< endl
				<< "InitColorRange:,,,"			<< endl
				<< "EndColor:,,,"				<< endl
				<< "Color:,,,"					<< endl
				<< "InitEmissiveColor:,,,"		<< endl
				<< "InitEmissiveColorRange:,,," << endl
				<< "EndEmissiveColor:,,,"		<< endl
				<< "EmissiveColor:,,,"			<< endl
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
				<< "eop" << endl
				<< endl
				<< endl
				<< "eof" << endl;
		}
	}


	//�G�~�b�^�t�@�C���̑���--------------------------------------------------------------------------------------------------------------

	//�t�@�C������p�[�e�B�N���̃p�����[�^�l��ǂݍ��݂܂��i.emitter�`���j
	void CEmitterFile::ReadEmitterFile(wstring filename, EmitterParameter& param) {
		ifstream ifs(GetExePath() + L"../effect/" + filename);
		string buf;

		while (ifs && getline(ifs, buf) && buf != "eoe") {

			vector<string> result;

			//������̕���
			Split(buf, ':', result);

			//�p�����[�^�l�̓ǂݏo��
			if (result[0] == "Name")					param.Name = StringToWString(result[1]);
			if (result[0] == "PositionRange")			param.PositionRange = StringToCVector(result[1]);
			if (result[0] == "InitVelocity")			param.InitVelocity = StringToCVector(result[1]);
			if (result[0] == "InitVelocityRange")		param.InitVelocityRange = StringToCVector(result[1]);
			if (result[0] == "Velocity")				param.Velocity = StringToCVector(result[1]);
			if (result[0] == "VelocityRange")			param.VelocityRange = StringToCVector(result[1]);
			if (result[0] == "InitRotation")			param.InitRotation = StringToCQuaternion(result[1]);
			if (result[0] == "InitRotationRange")		param.InitRotationRange = StringToCQuaternion(result[1]);
			if (result[0] == "Rotation")				param.Rotation = StringToCQuaternion(result[1]);
			if (result[0] == "RotationRange")			param.RotationRange = StringToCQuaternion(result[1]);
			if (result[0] == "LifeTime")				param.LifeTime = (unsigned int)StringToInt(result[1]);
			if (result[0] == "LifeTimeRange")			param.LifeTimeRange = (unsigned int)StringToInt(result[1]);
			if (result[0] == "Particle" || result[0] == "Emitter") {
				vector<string> value;

				Split(result[1], ',', value);

				param.GenerationList.push_back(StringToWString(value[0]));
				param.Interval.push_back((unsigned int)StringToInt(value[1]));
				param.Production.push_back((unsigned int)StringToInt(value[2]));
			}
		}
	}

	//�G�~�b�^�t�@�C�����쐬���܂�
	//�쐬�ꏊ�ɓ������O�̃t�@�C��������ꍇ�A�쐬����܂���
	void CreateEmitterFile(wstring filename){
		ofstream ofs(GetExePath() + L"../effect/" + filename + L".emitter", ios::out | ios::_Noreplace);

		if (ofs) {
			ofs << "Name:" << TWStringToString(filename) << endl
				<< "PositionRange:,," << endl
				<< "InitVelocity:,," << endl
				<< "InitVelocityRange:,," << endl
				<< "Velocity:,," << endl
				<< "VelocityRange:,," << endl
				<< "InitRotation:,,," << endl
				<< "InitRotationRange:,,," << endl
				<< "Rotation:,,," << endl
				<< "RotationRange:,,," << endl
				<< "LifeTime:" << endl
				<< "LifeTimeRange:" << endl
				<< "Particle:\"\",," << endl
				<< "eoe" << endl
				<< endl
				<< endl
				<< "eof" << endl;
		}
	}

}
