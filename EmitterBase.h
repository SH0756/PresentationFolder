namespace nel {

	//�G�~�b�^�̃x�[�X�N���X
	class CEmitterBase : public CEmitterFile {
	public:
		//�R���X�g���N�^
		CEmitterBase(wstring filename) : CEmitterFile(filename) {
			FindAmountChange();
		}

		//�G�~�b�^�̃p�����[�^�l�̕ω��ʂ����߂܂�
		void FindAmountChange();
	};

}