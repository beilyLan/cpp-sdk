/*******************************************************************************
 *  @file      IQiniuRemoteBatchFiles.h 2013\11\25 17:10:59 $
 *  @author    Wang Xiaotao<wangxiaotao1980@gmail.com> (���ı������)
 *
 ******************************************************************************/

#ifndef IQINIUREMOTEBATCHFILES_6D902195_7AB3_4F5C_8CF4_EE662C8A1D10_H__
#define IQINIUREMOTEBATCHFILES_6D902195_7AB3_4F5C_8CF4_EE662C8A1D10_H__

#include "QiniuConfig.h"
#include "QiniuError.h"

#include "IHttpSetting.h"


#include <string>
/******************************************************************************/


QINIU_NAMESPACE_BEGIN

struct QiniuToken;
struct QiniuBucketKey;
struct QiniuSrcAndDestBucketKey;


/**
 * The class <code>IQiniuRemoteBatchFile</code>Զ���ļ����������ӿ�
 *
 */
struct QINIU_API_DECL IQiniuRemoteBatchFiles : public IHttpSetting
{
public:

    /**
     * �����õ��ļ���Ϣ
     *
     * @param   [in] const QiniuToken & token           �û�token��Ϣ
     * @param   [in] const QiniuBucketKey * bucketKeys  QiniuBucketKey����ͷָ�룬������Ҫ�����õ����ļ����ƣ�
     * @param   [in] const int bucketKeysLen            �ϸ�����bucketKeys����ĳ��ȣ�
     * @param   [out] std::string & jsonstr             ����ֵ��json�ַ������� QiniuCode QINIU_OK �������� ָ����ѯfiles����Ϣ
     * @return  QiniuCode                               �����룬��ֵΪQINIU_OKʱ�򣬱�ʾ��ȷ���أ�����ɲ�ѯ
     *                                                  IQiniuRemoteFile::getLastErrorInfo()�õ���ʾ��Ϣ
     * @exception <code>���쳣�׳�</code>
     */
    
    virtual QiniuCode getRemoteBatchFilesInfo( IN const QiniuToken&     token,
                                               IN const QiniuBucketKey* bucketKeys,
                                               IN const int             bucketKeysLen,
                                               OUT std::string&         jsonstr)             = 0;

    /**
     * �����ƶ�Զ���ļ�
     *
     * @param   IN const QiniuToken & token                        �û�token��Ϣ
     * @param   IN const QiniuSrcAndDestBucketKey * bucketKeys     QiniuSrcAndDestBucketKey����ͷָ�룬������Ҫ�����ƶ����ļ���Դ��Ŀ������
     * @param   IN const int bucketKeysLen                         bucketKeys���鳤��
     * @param   OUT std::string & jsonstr                          ����ֵ��json�ַ������� QiniuCode QINIU_OK �������� ָ���ƶ�files��������Ϣ
     * @return  QINIU_NAMESPACE::QiniuCode                         �����룬��ֵΪQINIU_OKʱ�򣬱�ʾ��ȷ���أ�����ɲ�ѯ
     *                                                             IQiniuRemoteFile::getLastErrorInfo()�õ���ʾ��Ϣ
     * @exception <code>���쳣�׳�</code>
     */
    
    virtual QiniuCode moveRemoteBatchFiles( IN const QiniuToken&     token,
                                            IN const QiniuSrcAndDestBucketKey* bucketKeys,
                                            IN const int             bucketKeysLen,
                                            OUT std::string&         jsonstr)             = 0;

    
    /**
     * ��������Զ���ļ�
     *
     * @param   [in]  const QiniuToken & token                       �û�token��Ϣ
     * @param   [in]  const QiniuSrcAndDestBucketKey * bucketKeys    QiniuSrcAndDestBucketKey����ͷָ�룬������Ҫ�����ƶ����ļ���Դ��Ŀ������
     * @param   [in]  const int bucketKeysLen                        bucketKeys���鳤�� 
     * @param   [out] std::string & jsonstr                          ����ֵ��json�ַ������� QiniuCode QINIU_OK �������� ָ������files��������Ϣ
     * @return  QINIU_NAMESPACE::QiniuCode                           �����룬��ֵΪQINIU_OKʱ�򣬱�ʾ��ȷ���أ�����ɲ�ѯ
     *                                                               IQiniuRemoteFile::getLastErrorInfo()�õ���ʾ��Ϣ
     * @exception <code>���쳣�׳�</code>
     */
    
    virtual QiniuCode copyRemoteBatchFiles( IN const QiniuToken&               token,
                                            IN const QiniuSrcAndDestBucketKey* bucketKeys,
                                            IN const int                       bucketKeysLen,
                                            OUT std::string&                   jsonstr)     = 0;
    
    /**
     * ����ɾ��Զ���ļ�
     *
     * @param   [in]  const QiniuToken & token                   �û�token��Ϣ
     * @param   [in]  const QiniuBucketKey * bucketKeys          QiniuBucketKey����ͷָ�룬������Ҫ����ɾ�����ļ����ƣ�
     * @param   [in]  const int bucketKeysLen                    bucketKeys���鳤��
     * @param   [out] std::string & jsonstr                      ����ֵ��json�ַ������� QiniuCode QINIU_OK �������� ָ��ɾ��files��������Ϣ
     * @return  QINIU_NAMESPACE::QiniuCode                       �����룬��ֵΪQINIU_OKʱ�򣬱�ʾ��ȷ���أ�����ɲ�ѯ
     *                                                               IQiniuRemoteFile::getLastErrorInfo()�õ���ʾ��Ϣ
     * @exception <code>���쳣�׳�</code>
     */
    
    virtual QiniuCode deleteRemoteBatchFiles( IN  const QiniuToken&     token,
                                              IN  const QiniuBucketKey* bucketKeys,
                                              IN  const int             bucketKeysLen,
                                              OUT std::string&         jsonstr)             = 0;
    

    /**
     * ���Ϸ��ӿڷ��ط�QINIU_OK������ʱ�������������Ϣ
     *
     * @return  const char*������Ϣ������ָ�����һ�γ������Ϣ
     * @exception <code>���쳣�׳�</code>
     */
    virtual const char* getLastErrorInfo()                                                  = 0;


    ~IQiniuRemoteBatchFiles() = 0;
};

QINIU_NAMESPACE_END

/******************************************************************************/
#endif// IQINIUREMOTEBATCHFILES_6D902195_7AB3_4F5C_8CF4_EE662C8A1D10_H__