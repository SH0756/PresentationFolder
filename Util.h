namespace nel {

	//文字列の拡張-------------------------------------------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------------------------------
	//文字列相互変換参照サイト
	//https://gist.github.com/TAMAGO-JP/31f0030d26b321a9548e

	// シングルバイト、マルチバイト文字列化関数
	inline string TWStringToString(const wstring& arg_wstr)
	{
		// 文字数
		size_t length = arg_wstr.size();

		// 変換後文字数
		size_t convLength;

		// 仮の受け皿を用意（文字数×2ありゃ十分でしょう）
		char *c = (char*)malloc(sizeof(char)* length * 2);

		// 変換
		wcstombs_s(&convLength, c, sizeof(char)* length * 2, arg_wstr.c_str(), length * 2);

		// 返り値へ保存
		string result(c);

		// 仮の受け皿を破棄
		free(c);

		return result;
	};

	// ワイド文字列化関数
	inline wstring StringToWString(const string& arg_str)
	{
		// 文字数
		size_t length = arg_str.size();

		// 変換後文字数
		size_t convLength;

		// 仮の受け皿を用意
		wchar_t *wc = (wchar_t*)malloc(sizeof(wchar_t)* (length + 2));

		// 変換
		mbstowcs_s(&convLength, wc, length + 1, arg_str.c_str(), _TRUNCATE);

		// 返り値へ保存
		wstring str(wc);

		// 仮の受け皿を破棄
		free(wc);

		return str;
	};
	//---------------------------------------------------------------------------------------------------------------------

	// string から bool への変換
	inline bool StringToBool(const string& str) {
		if (str == "false") return false;
		else { return true; }
	}

	// string から int への変換
	inline int StringToInt(const string& str) {
		stringstream ss(str);
		int result;
		ss >> result;
		return result;
	}

	// string から float への変換
	inline float StringToFloat(const string& str) {
		stringstream ss(str);
		float result;
		ss >> result;
		return result;
	}

	//文字列の分割
	// str を delim で区切って、 result に入れます
	inline void Split(const string& str, char delim, vector<string>& result) {
		stringstream ss(str);
		string s;
		while (getline(ss, s, delim)) {
			result.push_back(s);
		}
	}

	// project へのパス
	//inline wstring GetExePath() { return L"C:/Users/vantan/Desktop/ゲーム制作/Games/EffectSample/ParticleFile/project213_ParticleFile/Main/"; }



	//HigPenの拡張----------------------------------------------------------------------------------------------------------------------------------

	inline CVector StringToCVector(const string& vec) {
		vector<string> results;
		vector<float> resultf;

		nel:: Split(vec, ',', results);

		for (int i = 0; i < 3; i++) resultf.push_back(nel::StringToFloat(results[i]));

		return CVector(resultf[0], resultf[1], resultf[2]);
	}

	inline CColor StringToCColor(const string& color) {
		vector<string> results;
		vector<float> resultf;

		nel::Split(color, ',', results);

		for (int i = 0; i < 4; i++) resultf.push_back(nel::StringToFloat(results[i]));

		return CColor(resultf[0], resultf[1], resultf[2], resultf[3]);
	}

	inline CQuaternion StringToCQuaternion(const string& rotation) {
		vector<string> results;
		vector<float> resultf;

		nel::Split(rotation, ',', results);

		for (int i = 0; i < 4; i++) resultf.push_back(nel::StringToFloat(results[i]));

		return CQuaternion(Normalize(CVector(resultf[0], resultf[1], resultf[2])), resultf[3]);
	}

}