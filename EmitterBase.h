namespace nel {

	//エミッタのベースクラス
	class CEmitterBase : public CEmitterFile {
	public:
		//コンストラクタ
		CEmitterBase(wstring filename) : CEmitterFile(filename) {
			FindAmountChange();
		}

		//エミッタのパラメータ値の変化量を求めます
		void FindAmountChange();
	};

}