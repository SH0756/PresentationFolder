#include "Nel.h"

namespace nel {
	//パーティクルファイルの操作----------------------------------------------------------------------------------------------------------

	//ファイルからパーティクルのパラメータ値を読み込みます（.particle形式）
	void CParticleFile::ReadParticleFile(wstring filename, ParticleParameter& param) {
		ifstream ifs(GetExePath() + L"../effect/" + filename);
		string buf;

		while (ifs && getline(ifs, buf) && buf != "eop") {

			vector<string> result;

			//文字列の分割
			Split(buf, ':', result);

			//パラメータ値の読み出し
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

	//パーティクルファイルを作成します
	//作成場所に同じ名前のファイルがある場合、作成されません
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


	//エミッタファイルの操作--------------------------------------------------------------------------------------------------------------

	//ファイルからパーティクルのパラメータ値を読み込みます（.emitter形式）
	void CEmitterFile::ReadEmitterFile(wstring filename, EmitterParameter& param) {
		ifstream ifs(GetExePath() + L"../effect/" + filename);
		string buf;

		while (ifs && getline(ifs, buf) && buf != "eoe") {

			vector<string> result;

			//文字列の分割
			Split(buf, ':', result);

			//パラメータ値の読み出し
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

	//エミッタファイルを作成します
	//作成場所に同じ名前のファイルがある場合、作成されません
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
