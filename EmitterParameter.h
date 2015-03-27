namespace nel {

	//エミッタパラメータ
	struct EmitterParameter {
	public:
		wstring					Name;						//エミッタ名
		CVector					PositionRange;				//生成位置の幅
		CVector					InitVelocity;				//初期加速度
		CVector					InitVelocityRange;			//初期加速度の幅
		CVector					Velocity;					//加速度の変化量
		CVector					VelocityRange;				//加速度の幅
		CQuaternion				InitRotation;				//初期回転量
		CQuaternion				InitRotationRange;			//初期回転量の幅
		CQuaternion				Rotation;					//回転量の変化量
		CQuaternion				RotationRange;				//回転量の幅
		unsigned int			LifeTime;					//生存時間（フレーム単位）
		unsigned int			LifeTimeRange;				//生存時間の幅
		vector<wstring>			EGenerationList;			//エミッタ生成リスト
		vector<unsigned int>	EInterval;					//エミッタ生成間隔
		vector<unsigned int>	EProduction;				//エミッタ生成量
		vector<wstring>			PGenerationList;			//パーティクル生成リスト
		vector<unsigned int>	PInterval;					//パーティクル生成間隔
		vector<unsigned int>	PProduction;				//パーティクル生成量

		//コンストラクタ

		//引数なしコンストラクタ
		EmitterParameter() :
			Name(L""),
			PositionRange(CVector()),
			InitVelocity(CVector()), InitVelocityRange(CVector()), Velocity(CVector()), VelocityRange(CVector()), 
			InitRotation(CQuaternion()), InitRotationRange(CQuaternion()), Rotation(CQuaternion()), RotationRange(CQuaternion()), 
			LifeTime(0), LifeTimeRange(0) {}

		void Movement() {
			if (LifeTimeRange > LifeTime) LifeTimeRange = LifeTime - 1;
			LifeTime = (unsigned int)(LifeTime + LifeTimeRange * Random(-1, 1));
			Velocity += (VelocityRange * Random(-1, 1));
			Rotation *= (RotationRange * Random(-1, 1));
		}

		//パラメータ値を返します
		EmitterParameter& GetParameter() { return *this; }
	};
}