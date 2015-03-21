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
		vector<wstring>			GenerationList;				//生成リスト
		vector<unsigned int>	Interval;					//生成間隔
		vector<unsigned int>	Production;					//生成量

		//コンスタラクタ

		//引数なしコンストラクタ
		EmitterParameter() :
			Name(L""),
			PositionRange(CVector()),
			InitVelocity(CVector()), InitVelocityRange(CVector()), Velocity(CVector()), VelocityRange(CVector()), 
			InitRotation(CQuaternion()), InitRotationRange(CQuaternion()), Rotation(CQuaternion()), RotationRange(CQuaternion()), 
			LifeTime(0), LifeTimeRange(0) {}
	};
}