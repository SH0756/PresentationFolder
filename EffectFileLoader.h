namespace nel {

	//パーティクルファイルの操作-----------------------------------------------------------------------------------------
	class CParticleFile : public ParticleParameter {
	public:
		//引数なしコンストラクタ
		CParticleFile() {}

		//filename からパラメータ値を読み込みます
		CParticleFile(wstring filename) {
			ReadParticleFile(filename);
		}

		//ファイルからパーティクルのパラメータ値を読み込みます（.particle形式）
		void ReadParticleFile(wstring filename);
	};

	//パーティクルファイルを作成します
	//作成場所に同じ名前のファイルがある場合、作成されません
	void CreateParticleFile(wstring filename);


	//エミッタファイルの操作クラス-----------------------------------------------------------------------------------------------
	class CEmitterFile : public EmitterParameter {
	public:
		//引数なしコンストラクタ
		CEmitterFile() {}

		//filename からパラメータ値を読み込みます
		CEmitterFile(wstring filename) {
			ReadEmitterFile(filename);
		}

		//ファイルからエミッタのパラメータ値を読み込みます（.emitter形式）
		void ReadEmitterFile(wstring filename);
	};

	//エミッタファイルを作成します
	//作成場所に同じ名前のファイルがある場合、作成されません
	void CreateEmitterFile(wstring filename);
}
