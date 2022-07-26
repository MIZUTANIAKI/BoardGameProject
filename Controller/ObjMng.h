#pragma once
#include <map>
//#define CPU_MAX 9


//#define CHARA_MAX_HITCOLL			2048		// 処理するコリジョンポリゴンの最大数
//#define CHARA_ENUM_DEFAULT_SIZE		3000.0f		// 周囲のポリゴン検出に使用する球の初期サイズ
//#define CHARA_HIT_WIDTH				3000.0f		// 当たり判定カプセルの半径
//#define CHARA_HIT_HEIGHT			1000.0f		// 当たり判定カプセルの高さ
//#define CHARA_HIT_PUSH_POWER		40.0f		// キャラクター同士で当たったときの押し出される力

#define lpobjlMng ObjMng::GetInstance()

class ObjMng
{
public:
	static ObjMng& GetInstance(void)
	{

		Create();
		return *sInstance;
	}

	static void Create()
	{
		if (sInstance == nullptr)
		{
			sInstance = new ObjMng();
		}
	}

	static void Destroy()
	{
		if (sInstance != nullptr)
		{
			delete sInstance;
		}
		sInstance = nullptr;
	}
	
	/// <summary>
	/// 描画予約された3Dモデルを描画させる。
	/// シーンの描画処理で必ず呼び出すこと。
	/// </summary>
	/// <param name=""></param>
	void DrawNaw(void);

	/// <summary>
	/// 描画予約リストを削除する
	/// メインループの先頭で必ず呼び出すこと。
	/// </summary>
	/// <param name=""></param>
	void ReSetD(void);

	/// <summary>
	/// 3Dモデルの位置情報を設定する。
	/// </summary>
	/// <param name="pos">座標</param>
	/// <param name="mv1">mv1モデルのID</param>
	void Setobjpos(int mv1,VECTOR pos);					

	/// <summary>
	/// 3Dモデルを描画する。
	/// 描画させるとき、マイフレーム必要
	/// </summary>
	/// <param name="mv1">mv1モデルのID</param>
	void ObjDraw(int mv1);

	/// <summary>
	/// MV1モデルを回転させる
	/// </summary>
	/// <param name="mv1">mv1モデルのID</param>
	/// <param name="moveangle">角度</param>
	void SetRotation(int mv1,float moveangle);

	/// <summary>
	/// モデルデータの拡縮設定をする。
	/// 1.0fをデフォルトとしてどのくらいかを設定。
	/// ※マイナス値使用禁止。
	/// </summary>
	/// <param name="mv1">mv1モデルのID</param>
	/// <param name="scale">拡縮値</param>
	void SetScale(int mv1, VECTOR scale);

	//bool ObjCollHit(VECTOR pos, UNIT_ID id);

	/// <summary>
	/// 3Dモデルデータを読み込む。
	/// 返り値はID。描画させたいときに必要。
	/// 
	/// 引数はディレクトリ[MV1Date]に格納してある前提なのでMV1Dateは省略
	/// </summary>
	/// <param name="fileName">3Dモデルファイル名</param>
	/// <returns>ID</returns>
	int LoadModel(std::string fileName);

	/// <summary>
	/// 保存されている3DモデルをIDから削除する
	/// 
	/// 不要なモデルは必ず削除すること。
	/// </summary>
	/// <param name="Mhandle"></param>
	void DeleteModel(int mv1);

	/// <summary>
	/// 格納されているモデルデータをすべて削除する。
	/// シーン切り替え時などで使用を想定。
	/// </summary>
	/// <param name=""></param>
	void ReSetModelDate(void);

	/// <summary>
	/// すでにロード済みのモデルデータのコピーを生成する。
	/// 複数体出る敵などは、オリジナルではなくコピーを使用すること。
	/// 返り値はコピーのID。
	/// </summary>
	/// <param name="mv1"></param>
	/// <returns></returns>
	int CopyModel(int mv1);

	/// <summary>
	/// IDからモデルハンドルを取得する。
	/// </summary>
	/// <param name="mv1"></param>
	/// <returns></returns>
	int GetModelHandle(int mv1);

	/// <summary>
	/// 描画本体
	/// </summary>
	/// <param name="handl"></param>
	void DrawSystem(int handl);

private:
	static ObjMng* sInstance;


	std::map<int,int> mv1List_;						//保存しているモデルデータ　ID：ハンドル

	std::vector<int> drawList_;						//描画予約キュー
	//std::vector<int> drawListnex_;				//描画予約キュー（すける）

	ObjMng();
	~ObjMng();
};

