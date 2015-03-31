namespace nel {

	//�G�~�b�^�p�����[�^
	struct EmitterParameter {
	public:
		wstring					EName;						//�G�~�b�^��
		CVector					EPositionRange;				//�����ʒu�̕�
		CVector					EInitVelocity;				//���������x
		CVector					EInitVelocityRange;			//���������x�̕�
		CVector					EVelocity;					//�����x�̕ω���
		CVector					EVelocityRange;				//�����x�̕�
		CQuaternion				EInitRotation;				//������]��
		CQuaternion				EInitRotationRange;			//������]�ʂ̕�
		CQuaternion				ERotation;					//��]�ʂ̕ω���
		CQuaternion				ERotationRange;				//��]�ʂ̕�
		unsigned int			ELifeTime;					//�������ԁi�t���[���P�ʁj
		unsigned int			ELifeTimeRange;				//�������Ԃ̕�
		vector<wstring>			EEGenerationList;			//�G�~�b�^�������X�g
		vector<unsigned int>	EEInterval;					//�G�~�b�^�����Ԋu
		vector<unsigned int>	EEProduction;				//�G�~�b�^������
		vector<wstring>			EPGenerationList;			//�p�[�e�B�N���������X�g
		vector<unsigned int>	EPInterval;					//�p�[�e�B�N�������Ԋu
		vector<unsigned int>	EPProduction;				//�p�[�e�B�N��������

		//�R���X�g���N�^

		//�����Ȃ��R���X�g���N�^
		EmitterParameter() :
			EName(L""),
			EPositionRange(CVector()),
			EInitVelocity(CVector()), EInitVelocityRange(CVector()), EVelocity(CVector()), EVelocityRange(CVector()), 
			EInitRotation(CQuaternion()), EInitRotationRange(CQuaternion()), ERotation(CQuaternion()), ERotationRange(CQuaternion()), 
			ELifeTime(0), ELifeTimeRange(0) {}

		//�p�����[�^�l��Ԃ��܂�
		EmitterParameter& GetParameter() { return *this; }
	};
}