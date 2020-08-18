typedef volatile uint8_t vu8;
typedef volatile uint16_t vu16;
typedef volatile uint32_t vu32;
typedef volatile uint64_t vu64;
typedef volatile int8_t vs8;
typedef volatile int16_t vs16;
typedef volatile int32_t vs32;
typedef volatile int64_t vs64;
typedef unsigned char SceUChar8;
typedef uint16_t SceUShort16;
typedef uint32_t SceUInt32;
typedef uint64_t SceUInt64;
typedef uint64_t SceULong64;
typedef char SceChar8;
typedef int16_t SceShort16;
typedef int32_t SceInt32;
typedef int64_t SceInt64;
typedef int64_t SceLong64;
typedef float SceFloat;
typedef float SceFloat32;
typedef short unsigned int SceWChar16;
typedef unsigned int SceWChar32;
typedef int SceBool;
typedef void SceVoid;
typedef void * ScePVoid;
typedef int SceUID;
typedef unsigned int SceSize;
typedef int SceSSize;
typedef unsigned char SceUChar;
typedef unsigned int SceUInt;
typedef int SceMode;
typedef SceInt64 SceOff;
typedef SceInt64 SceIores;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

struct ScePspSRect {
    short int x;
    short int y;
    short int w;
    short int h;
};

struct ScePspIRect {
    int x;
    int y;
    int w;
    int h;
};

struct ScePspL64Rect {
    SceLong64 x;
    SceLong64 y;
    SceLong64 w;
    SceLong64 h;
};

struct ScePspFRect {
    float x;
    float y;
    float w;
    float h;
};


struct ScePspSVector2 {
    short int x;
    short int y;
};

struct ScePspIVector2 {
    int x;
    int y;
};

struct ScePspL64Vector2 {
    SceLong64 x;
    SceLong64 y;
};

struct ScePspFVector2 {
    float x;
    float y;
};

union ScePspVector2 {
    ScePspFVector2 fv;
    ScePspIVector2 iv;
    float f[2];
    int i[2];
};

struct ScePspSVector3 {
    short int x;
    short int y;
    short int z;
};

struct ScePspIVector3 {
    int x;
    int y;
    int z;
};

struct ScePspL64Vector3 {
    SceLong64 x;
    SceLong64 y;
    SceLong64 z;
};

struct ScePspFVector3 {
    float x;
    float y;
    float z;
};

union ScePspVector3 {
    ScePspFVector3 fv;
    ScePspIVector3 iv;
    float f[3];
    int i[3];
};

struct ScePspSVector4 {
    short int x;
    short int y;
    short int z;
    short int w;
};

struct ScePspIVector4 {
    int x;
    int y;
    int z;
    int w;
};

struct ScePspL64Vector4 {
    SceLong64 x;
    SceLong64 y;
    SceLong64 z;
    SceLong64 w;
};

struct ScePspFVector4 {
    float x;
    float y;
    float z;
    float w;
};

struct ScePspFVector4Unaligned {
    float x;
    float y;
    float z;
    float w;
};

union ScePspVector4 {
    ScePspFVector4 fv;
    ScePspIVector4 iv;
    float f[4];
    int i[4];
};

struct ScePspIMatrix2 {
    ScePspIVector2 x;
    ScePspIVector2 y;
};

struct ScePspFMatrix2 {
    ScePspFVector2 x;
    ScePspFVector2 y;
};

union ScePspMatrix2 {
    ScePspFMatrix2 fm;
    ScePspIMatrix2 im;
    ScePspFVector2 fv[2];
    ScePspIVector2 iv[2];
    ScePspVector2 v[2];
    float f[4];
    int i[4];
};

struct ScePspIMatrix3 {
    ScePspIVector3 x;
    ScePspIVector3 y;
    ScePspIVector3 z;
};

struct ScePspFMatrix3 {
    ScePspFVector3 x;
    ScePspFVector3 y;
    ScePspFVector3 z;
};

union ScePspMatrix3 {
    ScePspFMatrix3 fm;
    ScePspIMatrix3 im;
    ScePspFVector3 fv[3];
    ScePspIVector3 iv[3];
    ScePspVector3 v[3];
    float f[9];
    int i[9];
};

struct ScePspIMatrix4 {
    ScePspIVector4 x;
    ScePspIVector4 y;
    ScePspIVector4 z;
    ScePspIVector4 w;
};

struct ScePspIMatrix4Unaligned {
    ScePspIVector4 x;
    ScePspIVector4 y;
    ScePspIVector4 z;
    ScePspIVector4 w;
};

struct ScePspFMatrix4 {
    ScePspFVector4 x;
    ScePspFVector4 y;
    ScePspFVector4 z;
    ScePspFVector4 w;
};

struct ScePspFMatrix4Unaligned {
    ScePspFVector4 x;
    ScePspFVector4 y;
    ScePspFVector4 z;
    ScePspFVector4 w;
};

union ScePspMatrix4 {
    ScePspFMatrix4 fm;
    ScePspIMatrix4 im;
    ScePspFVector4 fv[4];
    ScePspIVector4 iv[4];
    ScePspVector4 v[4];
    float f[16];
    int i[16];
};

struct ScePspFQuaternion {
    float x;
    float y;
    float z;
    float w;
};

struct ScePspFQuaternionUnaligned {
    float x;
    float y;
    float z;
    float w;
};

struct ScePspFColor {
    float r;
    float g;
    float b;
    float a;
};

struct ScePspFColorUnaligned {
    float r;
    float g;
    float b;
    float a;
};

typedef unsigned int ScePspRGBA8888;
typedef unsigned short ScePspRGBA4444;
typedef unsigned short ScePspRGBA5551;
typedef unsigned short ScePspRGB565;

union ScePspUnion32 {
    unsigned int ui;
    int i;
    unsigned short us[2];
    short int s[2];
    unsigned char uc[4];
    char c[4];
    float f;
    ScePspRGBA8888 rgba8888;
    ScePspRGBA4444 rgba4444[2];
    ScePspRGBA5551 rgba5551[2];
    ScePspRGB565 rgb565[2];
};

union ScePspUnion64 {
    SceULong64 ul;
    SceLong64 l;
    unsigned int ui[2];
    int i[2];
    unsigned short us[4];
    short int s[4];
    unsigned char uc[8];
    char c[8];
    float f[2];
    ScePspSRect sr;
    ScePspSVector4 sv;
    ScePspRGBA8888 rgba8888[2];
    ScePspRGBA4444 rgba4444[4];
    ScePspRGBA5551 rgba5551[4];
    ScePspRGB565 rgb565[4];
};

union ScePspUnion128 {
    SceULong64 ul[2];
    SceLong64 l[2];
    unsigned int ui[4];
    int i[4];
    unsigned short us[8];
    short int s[8];
    unsigned char uc[16];
    char c[16];
    float f[4];
    ScePspFRect fr;
    ScePspIRect ir;
    ScePspFVector4 fv;
    ScePspIVector4 iv;
    ScePspFQuaternion fq;
    ScePspFColor fc;
    ScePspRGBA8888 rgba8888[4];
    ScePspRGBA4444 rgba4444[8];
    ScePspRGBA5551 rgba5551[8];
    ScePspRGB565 rgb565[8];
};

struct ScePspDateTime {
    unsigned short year;
    unsigned short month;
    unsigned short day;
    unsigned short hour;
    unsigned short minute;
    unsigned short second;
    unsigned int microsecond;
};

enum PspHprmKeys
{
    PSP_HPRM_PLAYPAUSE = 0x1,
    PSP_HPRM_FORWARD = 0x4,
    PSP_HPRM_BACK = 0x8,
    PSP_HPRM_VOL_UP = 0x10,
    PSP_HPRM_VOL_DOWN = 0x20,
    PSP_HPRM_HOLD = 0x80
};

int sceHprmPeekCurrentKey(u32 *key);
int sceHprmPeekLatch(u32 *latch);
int sceHprmReadLatch(u32 *latch);
int sceHprmIsHeadphoneExist(void);
int sceHprmIsRemoteExist(void);
int sceHprmIsMicrophoneExist(void);

enum RegKeyTypes
{
    REG_TYPE_DIR = 1,
    REG_TYPE_INT = 2,
    REG_TYPE_STR = 3,
    REG_TYPE_BIN = 4,
};

typedef unsigned int REGHANDLE;


struct RegParam
{
    unsigned int regtype;
    char name[256];
    unsigned int namelen;
    unsigned int unk2;
    unsigned int unk3;
};

int sceRegOpenRegistry(struct RegParam *reg, int mode, REGHANDLE *h);
int sceRegFlushRegistry(REGHANDLE h);
int sceRegCloseRegistry(REGHANDLE h);
int sceRegOpenCategory(REGHANDLE h, const char *name, int mode, REGHANDLE *hd);
int sceRegRemoveCategory(REGHANDLE h, const char *name);
int sceRegCloseCategory(REGHANDLE hd);
int sceRegFlushCategory(REGHANDLE hd);
int sceRegGetKeyInfo(REGHANDLE hd, const char *name, REGHANDLE *hk, unsigned int *type, SceSize *size);
int sceRegGetKeyInfoByName(REGHANDLE hd, const char *name, unsigned int *type, SceSize *size);
int sceRegGetKeyValue(REGHANDLE hd, REGHANDLE hk, void *buf, SceSize size);
int sceRegGetKeyValueByName(REGHANDLE hd, const char *name, void *buf, SceSize size);
int sceRegSetKeyValue(REGHANDLE hd, const char *name, const void *buf, SceSize size);
int sceRegGetKeysNum(REGHANDLE hd, int *num);
int sceRegGetKeys(REGHANDLE hd, char *buf, int num);
int sceRegCreateKey(REGHANDLE hd, const char *name, int type, SceSize size);
int sceRegRemoveRegistry(struct RegParam *reg);

enum PspCtrlButtons
{
    PSP_CTRL_SELECT = 0x000001,
    PSP_CTRL_START = 0x000008,
    PSP_CTRL_UP = 0x000010,
    PSP_CTRL_RIGHT = 0x000020,
    PSP_CTRL_DOWN = 0x000040,
    PSP_CTRL_LEFT = 0x000080,
    PSP_CTRL_LTRIGGER = 0x000100,
    PSP_CTRL_RTRIGGER = 0x000200,
    PSP_CTRL_TRIANGLE = 0x001000,
    PSP_CTRL_CIRCLE = 0x002000,
    PSP_CTRL_CROSS = 0x004000,
    PSP_CTRL_SQUARE = 0x008000,
    PSP_CTRL_HOME = 0x010000,
    PSP_CTRL_HOLD = 0x020000,
    PSP_CTRL_NOTE = 0x800000,
    PSP_CTRL_SCREEN = 0x400000,
    PSP_CTRL_VOLUP = 0x100000,
    PSP_CTRL_VOLDOWN = 0x200000,
    PSP_CTRL_WLAN_UP = 0x040000,
    PSP_CTRL_REMOTE = 0x080000,
    PSP_CTRL_DISC = 0x1000000,
    PSP_CTRL_MS = 0x2000000,
};

enum PspCtrlMode
{
    PSP_CTRL_MODE_DIGITAL = 0,
    PSP_CTRL_MODE_ANALOG
};

struct SceCtrlData {
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};

struct SceCtrlLatch {
    unsigned int uiMake;
    unsigned int uiBreak;
    unsigned int uiPress;
    unsigned int uiRelease;
};

int sceCtrlSetSamplingCycle(int cycle);
int sceCtrlGetSamplingCycle(int *pcycle);
int sceCtrlSetSamplingMode(int mode);
int sceCtrlGetSamplingMode(int *pmode);
int sceCtrlPeekBufferPositive(SceCtrlData *pad_data, int count);
int sceCtrlPeekBufferNegative(SceCtrlData *pad_data, int count);
int sceCtrlReadBufferPositive(SceCtrlData *pad_data, int count);
int sceCtrlReadBufferNegative(SceCtrlData *pad_data, int count);
int sceCtrlPeekLatch(SceCtrlLatch *latch_data);
int sceCtrlReadLatch(SceCtrlLatch *latch_data);
int sceCtrlSetIdleCancelThreshold(int idlereset, int idleback);
int sceCtrlGetIdleCancelThreshold(int *idlerest, int *idleback);

struct pspChnnlsvContext1 {
    int mode;
    char buffer1[0x10];
    char buffer2[0x10];
    int unknown;
};

struct pspChnnlsvContext2 {
    char unknown[0x100];
};

int sceChnnlsv_E7833020(pspChnnlsvContext1 *ctx, int mode);
int sceChnnlsv_F21A1FCA(pspChnnlsvContext1 *ctx, unsigned char *data, int len);
int sceChnnlsv_C4C494F8(pspChnnlsvContext1 *ctx, unsigned char *hash, unsigned char *cryptkey);
int sceChnnlsv_ABFDFC8B(pspChnnlsvContext2 *ctx, int mode1, int mode2, unsigned char *hashkey, unsigned char *cipherkey);
int sceChnnlsv_850A7FA1(pspChnnlsvContext2 *ctx, unsigned char *data, int len);
int sceDisplay_driver_63E22A26(int pri, void *topaddr, int bufferwidth, int pixelformat, int sync);
int sceDisplay_driver_5B5AEFAD(int pri, void **topaddr, int *bufferwidth, int *pixelformat, int sync);
void sceDisplaySetBrightness(int level,int unk1);
void sceDisplayGetBrightness(int *level,int *unk1);

enum PspDisplayPixelFormats {
    PSP_DISPLAY_PIXEL_FORMAT_565 = 0,
    PSP_DISPLAY_PIXEL_FORMAT_5551,
    PSP_DISPLAY_PIXEL_FORMAT_4444,
    PSP_DISPLAY_PIXEL_FORMAT_8888
};

enum PspDisplaySetBufSync {
    PSP_DISPLAY_SETBUF_IMMEDIATE = 0,
    PSP_DISPLAY_SETBUF_NEXTFRAME = 1
};

enum PspDisplayErrorCodes
{
    SCE_DISPLAY_ERROR_OK = 0,
    SCE_DISPLAY_ERROR_POINTER = 0x80000103,
    SCE_DISPLAY_ERROR_ARGUMENT = 0x80000107
};

int sceDisplaySetMode(int mode, int width, int height);
int sceDisplayGetMode(int *pmode, int *pwidth, int *pheight);
int sceDisplaySetFrameBuf(void *topaddr, int bufferwidth, int pixelformat, int sync);
int sceDisplayGetFrameBuf(void **topaddr, int *bufferwidth, int *pixelformat, int sync);
unsigned int sceDisplayGetVcount(void);
int sceDisplayWaitVblankStart(void);
int sceDisplayWaitVblankStartCB(void);
int sceDisplayWaitVblank(void);
int sceDisplayWaitVblankCB(void);
int sceDisplayGetAccumulatedHcount(void);
int sceDisplayGetCurrentHcount(void);
float sceDisplayGetFramePerSec(void);
int sceDisplayIsForeground(void);
int sceDisplayIsVblank(void);
typedef void (*powerCallback_t)(int unknown, int powerInfo);

int scePowerRegisterCallback(int slot, SceUID cbid);
int scePowerUnregisterCallback(int slot);
int scePowerIsPowerOnline(void);
int scePowerIsBatteryExist(void);
int scePowerIsBatteryCharging(void);
int scePowerGetBatteryChargingStatus(void);
int scePowerIsLowBattery(void);
int scePowerGetBatteryLifePercent(void);
int scePowerGetBatteryLifeTime(void);
int scePowerGetBatteryTemp(void);
int scePowerGetBatteryElec(void);
int scePowerGetBatteryVolt(void);
int scePowerSetCpuClockFrequency(int cpufreq);
int scePowerSetBusClockFrequency(int busfreq);
int scePowerGetCpuClockFrequency(void);
int scePowerGetCpuClockFrequencyInt(void);
float scePowerGetCpuClockFrequencyFloat(void);
int scePowerGetBusClockFrequency(void);
int scePowerGetBusClockFrequencyInt(void);
float scePowerGetBusClockFrequencyFloat(void);
int scePowerSetClockFrequency(int pllfreq, int cpufreq, int busfreq);
int scePowerLock(int unknown);
int scePowerUnlock(int unknown);
int scePowerTick(int type);
int scePowerGetIdleTimer(void);
int scePowerIdleTimerEnable(int unknown);
int scePowerIdleTimerDisable(int unknown);
int scePowerRequestStandby(void);
int scePowerRequestSuspend(void);

enum IOAccessModes
{
    FIO_S_IFMT = 0xF000,
    FIO_S_IFLNK = 0x4000,
    FIO_S_IFDIR = 0x1000,
    FIO_S_IFREG = 0x2000,
    FIO_S_ISUID = 0x0800,
    FIO_S_ISGID = 0x0400,
    FIO_S_ISVTX = 0x0200,
    FIO_S_IRWXU = 0x01C0,
    FIO_S_IRUSR = 0x0100,
    FIO_S_IWUSR = 0x0080,
    FIO_S_IXUSR = 0x0040,
    FIO_S_IRWXG = 0x0038,
    FIO_S_IRGRP = 0x0020,
    FIO_S_IWGRP = 0x0010,
    FIO_S_IXGRP = 0x0008,
    FIO_S_IRWXO = 0x0007,
    FIO_S_IROTH = 0x0004,
    FIO_S_IWOTH = 0x0002,
    FIO_S_IXOTH = 0x0001,
};

enum IOFileModes
{
    FIO_SO_IFMT = 0x0038,
    FIO_SO_IFLNK = 0x0008,
    FIO_SO_IFDIR = 0x0010,
    FIO_SO_IFREG = 0x0020,
    FIO_SO_IROTH = 0x0004,
    FIO_SO_IWOTH = 0x0002,
    FIO_SO_IXOTH = 0x0001,
};

struct SceIoStat {
    SceMode st_mode;
    unsigned int st_attr;
    SceOff st_size;
    ScePspDateTime st_ctime;
    ScePspDateTime st_atime;
    ScePspDateTime st_mtime;
    unsigned int st_private[6];
};

struct SceIoDirent {
    SceIoStat d_stat;
    char d_name[256];
    void * d_private;
    int dummy;
};

enum IoAssignPerms
{
    IOASSIGN_RDWR = 0,
    IOASSIGN_RDONLY = 1
};

SceUID sceIoOpen(const char *file, int flags, SceMode mode);
SceUID sceIoOpenAsync(const char *file, int flags, SceMode mode);
int sceIoClose(SceUID fd);
int sceIoCloseAsync(SceUID fd);
int sceIoRead(SceUID fd, void *data, SceSize size);
int sceIoReadAsync(SceUID fd, void *data, SceSize size);
int sceIoWrite(SceUID fd, const void *data, SceSize size);
int sceIoWriteAsync(SceUID fd, const void *data, SceSize size);
SceOff sceIoLseek(SceUID fd, SceOff offset, int whence);
int sceIoLseekAsync(SceUID fd, SceOff offset, int whence);
int sceIoLseek32(SceUID fd, int offset, int whence);
int sceIoLseek32Async(SceUID fd, int offset, int whence);
int sceIoRemove(const char *file);
int sceIoMkdir(const char *dir, SceMode mode);
int sceIoRmdir(const char *path);
int sceIoChdir(const char *path);
int sceIoRename(const char *oldname, const char *newname);
SceUID sceIoDopen(const char *dirname);
int sceIoDread(SceUID fd, SceIoDirent *dir);
int sceIoDclose(SceUID fd);
int sceIoDevctl(const char *dev, unsigned int cmd, void *indata, int inlen, void *outdata, int outlen);
int sceIoAssign(const char *dev1, const char *dev2, const char *dev3, int mode, void* unk1, long unk2);
int sceIoUnassign(const char *dev);
int sceIoGetstat(const char *file, SceIoStat *stat);
int sceIoChstat(const char *file, SceIoStat *stat, int bits);
int sceIoIoctl(SceUID fd, unsigned int cmd, void *indata, int inlen, void *outdata, int outlen);
int sceIoIoctlAsync(SceUID fd, unsigned int cmd, void *indata, int inlen, void *outdata, int outlen);
int sceIoSync(const char *device, unsigned int unk);
int sceIoWaitAsync(SceUID fd, SceInt64 *res);
int sceIoWaitAsyncCB(SceUID fd, SceInt64 *res);
int sceIoPollAsync(SceUID fd, SceInt64 *res);
int sceIoGetAsyncStat(SceUID fd, int poll, SceInt64 *res);
int sceIoCancel(SceUID fd);
int sceIoGetDevType(SceUID fd);
int sceIoChangeAsyncPriority(SceUID fd, int pri);
int sceIoSetAsyncCallback(SceUID fd, SceUID cb, void *argp);
int sceKernelRegisterExitCallback(int cbid);
void sceKernelExitGame(void);

struct SceKernelLoadExecParam {
    SceSize size;
    SceSize args;
    void * argp;
    const char * key;
};

int sceKernelLoadExec(const char *file, struct SceKernelLoadExecParam *param);

struct SceModuleInfo {
    unsigned short modattribute;
    unsigned char modversion[2];
    char modname[27];
    char terminal;
    void * gp_value;
    void * ent_top;
    void * ent_end;
    void * stub_top;
    void * stub_end;
};

enum PspModuleInfoAttr
{
    PSP_MODULE_USER = 0,
    PSP_MODULE_NO_STOP = 0x0001,
    PSP_MODULE_SINGLE_LOAD = 0x0002,
    PSP_MODULE_SINGLE_START = 0x0004,
    PSP_MODULE_KERNEL = 0x1000,
};

struct SceKernelLMOption {
    SceSize size;
    SceUID mpidtext;
    SceUID mpiddata;
    unsigned int flags;
    char position;
    char access;
    char creserved[2];
};

struct SceKernelSMOption {
    SceSize size;
    SceUID mpidstack;
    SceSize stacksize;
    int priority;
    unsigned int attribute;
};

SceUID sceKernelLoadModule(const char *path, int flags, SceKernelLMOption *option);
SceUID sceKernelLoadModuleMs(const char *path, int flags, SceKernelLMOption *option);
SceUID sceKernelLoadModuleByID(SceUID fid, int flags, SceKernelLMOption *option);
SceUID sceKernelLoadModuleBufferUsbWlan(SceSize bufsize, void *buf, int flags, SceKernelLMOption *option);
int sceKernelStartModule(SceUID modid, SceSize argsize, void *argp, int *status, SceKernelSMOption *option);
int sceKernelStopModule(SceUID modid, SceSize argsize, void *argp, int *status, SceKernelSMOption *option);
int sceKernelUnloadModule(SceUID modid);
int sceKernelSelfStopUnloadModule(int unknown, SceSize argsize, void *argp);
int sceKernelStopUnloadSelfModule(SceSize argsize, void *argp, int *status, SceKernelSMOption *option);

struct SceKernelModuleInfo {
    SceSize size;
    char nsegment;
    char reserved[3];
    int segmentaddr[4];
    int segmentsize[4];
    unsigned int entry_addr;
    unsigned int gp_value;
    unsigned int text_addr;
    unsigned int text_size;
    unsigned int data_size;
    unsigned int bss_size;
    unsigned short attribute;
    unsigned char version[2];
    char name[28];
};

int sceKernelQueryModuleInfo(SceUID modid, SceKernelModuleInfo *info);
int sceKernelGetModuleIdList(SceUID *readbuf, int readbufsize, int *idcount);

enum PspSysMemBlockTypes {
    PSP_SMEM_Low = 0,
    PSP_SMEM_High,
    PSP_SMEM_Addr
};


typedef int SceKernelSysMemAlloc_t;

SceUID sceKernelAllocPartitionMemory(SceUID partitionid, const char *name, int type, SceSize size, void *addr);
int sceKernelFreePartitionMemory(SceUID blockid);
void * sceKernelGetBlockHeadAddr(SceUID blockid);
SceSize sceKernelTotalFreeMemSize(void);
SceSize sceKernelMaxFreeMemSize(void);
int sceKernelDevkitVersion(void);
int sceKernelSetCompiledSdkVersion(int version);
int sceKernelGetCompiledSdkVersion(void);

struct PspDebugRegBlock
{
    u32 frame[6];
    u32 r[32];
    u32 status;
    u32 lo;
    u32 hi;
    u32 badvaddr;
    u32 cause;
    u32 epc;
    float fpr[32];
    u32 fsr;
    u32 fir;
    u32 frame_ptr;
    u32 unused;
    u32 index;
    u32 random;
    u32 entrylo0;
    u32 entrylo1;
    u32 context;
    u32 pagemask;
    u32 wired;
    u32 cop0_7;
    u32 cop0_8;
    u32 cop0_9;
    u32 entryhi;
    u32 cop0_11;
    u32 cop0_12;
    u32 cop0_13;
    u32 cop0_14;
    u32 prid;
    u32 padding[100];
};

struct SceKernelSysClock {
    SceUInt32 low;
    SceUInt32 hi;
};

enum PspThreadAttributes
{

    PSP_THREAD_ATTR_VFPU = 0x00004000,
    PSP_THREAD_ATTR_USER = 0x80000000,
    PSP_THREAD_ATTR_USBWLAN = 0xa0000000,
    PSP_THREAD_ATTR_VSH = 0xc0000000,
    PSP_THREAD_ATTR_SCRATCH_SRAM = 0x00008000,
    PSP_THREAD_ATTR_NO_FILLSTACK = 0x00100000,
    PSP_THREAD_ATTR_CLEAR_STACK = 0x00200000,
};

typedef int (*SceKernelThreadEntry)(SceSize args, void *argp);

struct SceKernelThreadOptParam {
    SceSize size;
    SceUID stackMpid;
};

struct SceKernelThreadInfo {
    SceSize size;
    char name[32];
    SceUInt attr;
    int status;
    SceKernelThreadEntry entry;
    void * stack;
    int stackSize;
    void * gpReg;
    int initPriority;
    int currentPriority;
    int waitType;
    SceUID waitId;
    int wakeupCount;
    int exitStatus;
    SceKernelSysClock runClocks;
    SceUInt intrPreemptCount;
    SceUInt threadPreemptCount;
    SceUInt releaseCount;
};

struct SceKernelThreadRunStatus {
    SceSize size;
    int status;
    int currentPriority;
    int waitType;
    int waitId;
    int wakeupCount;
    SceKernelSysClock runClocks;
    SceUInt intrPreemptCount;
    SceUInt threadPreemptCount;
    SceUInt releaseCount;
};

enum PspThreadStatus
{
    PSP_THREAD_RUNNING = 1,
    PSP_THREAD_READY = 2,
    PSP_THREAD_WAITING = 4,
    PSP_THREAD_SUSPEND = 8,
    PSP_THREAD_STOPPED = 16,
    PSP_THREAD_KILLED = 32,
};

SceUID sceKernelCreateThread(const char *name, SceKernelThreadEntry entry, int initPriority,
        int stackSize, SceUInt attr, SceKernelThreadOptParam *option);
int sceKernelDeleteThread(SceUID thid);
int sceKernelStartThread(SceUID thid, SceSize arglen, void *argp);
int sceKernelExitThread(int status);
int sceKernelExitDeleteThread(int status);
int sceKernelTerminateThread(SceUID thid);
int sceKernelTerminateDeleteThread(SceUID thid);
int sceKernelSuspendDispatchThread(void);
int sceKernelResumeDispatchThread(int state);
int sceKernelSleepThread(void);
int sceKernelSleepThreadCB(void);
int sceKernelWakeupThread(SceUID thid);
int sceKernelCancelWakeupThread(SceUID thid);
int sceKernelSuspendThread(SceUID thid);
int sceKernelResumeThread(SceUID thid);
int sceKernelWaitThreadEnd(SceUID thid, SceUInt *timeout);
int sceKernelWaitThreadEndCB(SceUID thid, SceUInt *timeout);
int sceKernelDelayThread(SceUInt delay);
int sceKernelDelayThreadCB(SceUInt delay);
int sceKernelDelaySysClockThread(SceKernelSysClock *delay);
int sceKernelDelaySysClockThreadCB(SceKernelSysClock *delay);
int sceKernelChangeCurrentThreadAttr(int unknown, SceUInt attr);
int sceKernelChangeThreadPriority(SceUID thid, int priority);
int sceKernelRotateThreadReadyQueue(int priority);
int sceKernelReleaseWaitThread(SceUID thid);
int sceKernelGetThreadId(void);
int sceKernelGetThreadCurrentPriority(void);
int sceKernelGetThreadExitStatus(SceUID thid);
int sceKernelCheckThreadStack(void);
int sceKernelGetThreadStackFreeSize(SceUID thid);
int sceKernelReferThreadStatus(SceUID thid, SceKernelThreadInfo *info);
int sceKernelReferThreadRunStatus(SceUID thid, SceKernelThreadRunStatus *status);

struct SceKernelSemaOptParam {
    SceSize size;
};

struct SceKernelSemaInfo {
    SceSize size;
    char name[32];
    SceUInt attr;
    int initCount;
    int currentCount;
    int maxCount;
    int numWaitThreads;
};

SceUID sceKernelCreateSema(const char *name, SceUInt attr, int initVal, int maxVal, SceKernelSemaOptParam *option);
int sceKernelDeleteSema(SceUID semaid);
int sceKernelSignalSema(SceUID semaid, int signal);
int sceKernelWaitSema(SceUID semaid, int signal, SceUInt *timeout);
int sceKernelWaitSemaCB(SceUID semaid, int signal, SceUInt *timeout);
int sceKernelPollSema(SceUID semaid, int signal);
int sceKernelReferSemaStatus(SceUID semaid, SceKernelSemaInfo *info);

struct SceKernelEventFlagInfo {
    SceSize size;
    char name[32];
    SceUInt attr;
    SceUInt initPattern;
    SceUInt currentPattern;
    int numWaitThreads;
};

struct SceKernelEventFlagOptParam {
    SceSize size;
};

enum PspEventFlagWaitTypes
{
    PSP_EVENT_WAITAND = 0,
    PSP_EVENT_WAITOR = 1,
    PSP_EVENT_WAITCLEAR = 0x20
};

enum PspEventFlagAttributes
{
    PSP_EVENT_WAITMULTIPLE = 0x200
};

SceUID sceKernelCreateEventFlag(const char *name, int attr, int bits, SceKernelEventFlagOptParam *opt);
int sceKernelSetEventFlag(SceUID evid, u32 bits);
int sceKernelClearEventFlag(SceUID evid, u32 bits);
int sceKernelPollEventFlag(int evid, u32 bits, u32 wait, u32 *outBits);
int sceKernelWaitEventFlag(int evid, u32 bits, u32 wait, u32 *outBits, SceUInt *timeout);
int sceKernelWaitEventFlagCB(int evid, u32 bits, u32 wait, u32 *outBits, SceUInt *timeout);
int sceKernelDeleteEventFlag(int evid);
int sceKernelReferEventFlagStatus(SceUID event, SceKernelEventFlagInfo *status);

struct SceKernelMbxOptParam {
    SceSize size;
};

struct SceKernelMbxInfo {
    SceSize size;
    char name[32];
    SceUInt attr;
    int numWaitThreads;
    int numMessages;
    void *firstMessage;
};

struct SceKernelMsgPacket {
    struct SceKernelMsgPacket *next;
    SceUChar msgPriority;
    SceUChar dummy[3];
};

SceUID sceKernelCreateMbx(const char *name, SceUInt attr, SceKernelMbxOptParam *option);
int sceKernelDeleteMbx(SceUID mbxid);
int sceKernelSendMbx(SceUID mbxid, void *message);
int sceKernelReceiveMbx(SceUID mbxid, void **pmessage, SceUInt *timeout);
int sceKernelReceiveMbxCB(SceUID mbxid, void **pmessage, SceUInt *timeout);
int sceKernelPollMbx(SceUID mbxid, void **pmessage);
int sceKernelCancelReceiveMbx(SceUID mbxid, int *pnum);
int sceKernelReferMbxStatus(SceUID mbxid, SceKernelMbxInfo *info);

typedef SceUInt (*SceKernelAlarmHandler)(void *common);

struct SceKernelAlarmInfo {
    SceSize size;
    SceKernelSysClock schedule;
    SceKernelAlarmHandler handler;
    void * common;
};

SceUID sceKernelSetAlarm(SceUInt clock, SceKernelAlarmHandler handler, void *common);
SceUID sceKernelSetSysClockAlarm(SceKernelSysClock *clock, SceKernelAlarmHandler handler, void *common);
int sceKernelCancelAlarm(SceUID alarmid);
int sceKernelReferAlarmStatus(SceUID alarmid, SceKernelAlarmInfo *info);

typedef int (*SceKernelCallbackFunction)(int arg1, int arg2, void *arg);

struct SceKernelCallbackInfo {
    SceSize size;
    char name[32];
    SceUID threadId;
    SceKernelCallbackFunction callback;
    void * common;
    int notifyCount;
    int notifyArg;
};

int sceKernelCreateCallback(const char *name, SceKernelCallbackFunction func, void *arg);
int sceKernelReferCallbackStatus(SceUID cb, SceKernelCallbackInfo *status);
int sceKernelDeleteCallback(SceUID cb);
int sceKernelNotifyCallback(SceUID cb, int arg2);
int sceKernelCancelCallback(SceUID cb);
int sceKernelGetCallbackCount(SceUID cb);
int sceKernelCheckCallback(void);

enum SceKernelIdListType
{
    SCE_KERNEL_TMID_Thread = 1,
    SCE_KERNEL_TMID_Semaphore = 2,
    SCE_KERNEL_TMID_EventFlag = 3,
    SCE_KERNEL_TMID_Mbox = 4,
    SCE_KERNEL_TMID_Vpl = 5,
    SCE_KERNEL_TMID_Fpl = 6,
    SCE_KERNEL_TMID_Mpipe = 7,
    SCE_KERNEL_TMID_Callback = 8,
    SCE_KERNEL_TMID_ThreadEventHandler = 9,
    SCE_KERNEL_TMID_Alarm = 10,
    SCE_KERNEL_TMID_VTimer = 11,
    SCE_KERNEL_TMID_SleepThread = 64,
    SCE_KERNEL_TMID_DelayThread = 65,
    SCE_KERNEL_TMID_SuspendThread = 66,
    SCE_KERNEL_TMID_DormantThread = 67,
};

int sceKernelGetThreadmanIdList(enum SceKernelIdListType type, SceUID *readbuf, int readbufsize, int *idcount);

struct SceKernelSystemStatus {
    SceSize size;
    SceUInt status;
    SceKernelSysClock idleClocks;
    SceUInt comesOutOfIdleCount;
    SceUInt threadSwitchCount;
    SceUInt vfpuSwitchCount;
};

int sceKernelReferSystemStatus(SceKernelSystemStatus *status);
SceUID sceKernelCreateMsgPipe(const char *name, int part, int attr, void *unk1, void *opt);
int sceKernelDeleteMsgPipe(SceUID uid);
int sceKernelSendMsgPipe(SceUID uid, void *message, unsigned int size, int unk1, void *unk2, unsigned int *timeout);
int sceKernelSendMsgPipeCB(SceUID uid, void *message, unsigned int size, int unk1, void *unk2, unsigned int *timeout);
int sceKernelTrySendMsgPipe(SceUID uid, void *message, unsigned int size, int unk1, void *unk2);
int sceKernelReceiveMsgPipe(SceUID uid, void *message, unsigned int size, int unk1, void *unk2, unsigned int *timeout);
int sceKernelReceiveMsgPipeCB(SceUID uid, void *message, unsigned int size, int unk1, void *unk2, unsigned int *timeout);
int sceKernelTryReceiveMsgPipe(SceUID uid, void *message, unsigned int size, int unk1, void *unk2);
int sceKernelCancelMsgPipe(SceUID uid, int *psend, int *precv);

struct SceKernelMppInfo {
    SceSize size;
    char name[32];
    SceUInt attr;
    int bufSize;
    int freeSize;
    int numSendWaitThreads;
    int numReceiveWaitThreads;
};

int sceKernelReferMsgPipeStatus(SceUID uid, SceKernelMppInfo *info);

struct SceKernelVplOptParam {
    SceSize size;
};

SceUID sceKernelCreateVpl(const char *name, int part, int attr, unsigned int size, struct SceKernelVplOptParam *opt);
int sceKernelDeleteVpl(SceUID uid);
int sceKernelAllocateVpl(SceUID uid, unsigned int size, void **data, unsigned int *timeout);
int sceKernelAllocateVplCB(SceUID uid, unsigned int size, void **data, unsigned int *timeout);
int sceKernelTryAllocateVpl(SceUID uid, unsigned int size, void **data);
int sceKernelFreeVpl(SceUID uid, void *data);
int sceKernelCancelVpl(SceUID uid, int *pnum);

struct SceKernelVplInfo {
    SceSize size;
    char name[32];
    SceUInt attr;
    int poolSize;
    int freeSize;
    int numWaitThreads;
};

struct SceKernelFplOptParam {
    SceSize size;
};

int sceKernelCreateFpl(const char *name, int part, int attr, unsigned int size, unsigned int blocks, struct SceKernelFplOptParam *opt);
int sceKernelDeleteFpl(SceUID uid);
int sceKernelAllocateFpl(SceUID uid, void **data, unsigned int *timeout);
int sceKernelAllocateFplCB(SceUID uid, void **data, unsigned int *timeout);
int sceKernelTryAllocateFpl(SceUID uid, void **data);
int sceKernelFreeFpl(SceUID uid, void *data);
int sceKernelCancelFpl(SceUID uid, int *pnum);

struct SceKernelFplInfo {
    SceSize size;
    char name[32];
    SceUInt attr;
    int blockSize;
    int numBlocks;
    int freeBlocks;
    int numWaitThreads;
};

int sceKernelReferFplStatus(SceUID uid, SceKernelFplInfo *info);
void _sceKernelReturnFromTimerHandler(void);
void _sceKernelReturnFromCallback(void);
int sceKernelUSec2SysClock(unsigned int usec, SceKernelSysClock *clock);
SceInt64 sceKernelUSec2SysClockWide(unsigned int usec);
int sceKernelSysClock2USec(SceKernelSysClock *clock, unsigned int *low, unsigned int *high);
int sceKernelSysClock2USecWide(SceInt64 clock, unsigned int *low, unsigned int *high);
int sceKernelGetSystemTime(SceKernelSysClock *time);
SceInt64 sceKernelGetSystemTimeWide(void);
unsigned int sceKernelGetSystemTimeLow(void);

struct SceKernelVTimerOptParam {
    SceSize size;
};

typedef SceUInt (*SceKernelVTimerHandler)(SceUID uid, SceKernelSysClock *, SceKernelSysClock *, void *);
typedef SceUInt (*SceKernelVTimerHandlerWide)(SceUID uid, SceInt64, SceInt64, void *);
int sceKernelSetVTimerHandler(SceUID uid, SceKernelSysClock *time, SceKernelVTimerHandler handler, void *common);
int sceKernelSetVTimerHandlerWide(SceUID uid, SceInt64 time, SceKernelVTimerHandlerWide handler, void *common);
int sceKernelCancelVTimerHandler(SceUID uid);
SceUID sceKernelCreateVTimer(const char *name, struct SceKernelVTimerOptParam *opt);
int sceKernelDeleteVTimer(SceUID uid);
int sceKernelGetVTimerBase(SceUID uid, SceKernelSysClock *base);
SceInt64 sceKernelGetVTimerBaseWide(SceUID uid);
int sceKernelGetVTimerTime(SceUID uid, SceKernelSysClock *time);
SceInt64 sceKernelGetVTimerTimeWide(SceUID uid);
int sceKernelSetVTimerTime(SceUID uid, SceKernelSysClock *time);
SceInt64 sceKernelSetVTimerTimeWide(SceUID uid, SceInt64 time);
int sceKernelStartVTimer(SceUID uid);
int sceKernelStopVTimer(SceUID uid);

struct SceKernelVTimerInfo {
    SceSize size;
    char name[32];
    int active;
    SceKernelSysClock base;
    SceKernelSysClock current;
    SceKernelSysClock schedule;
    SceKernelVTimerHandler handler;
    void * common;
};

int sceKernelReferVTimerStatus(SceUID uid, SceKernelVTimerInfo *info);
void _sceKernelExitThread(void);

enum SceKernelIdListType sceKernelGetThreadmanIdType(SceUID uid);
typedef int (*SceKernelThreadEventHandler)(int mask, SceUID thid, void *common);

struct SceKernelThreadEventHandlerInfo {
    SceSize size;
    char name[32];
    SceUID threadId;
    int mask;
    SceKernelThreadEventHandler handler;
    void * common;
};

enum ThreadEventIds
{
    THREADEVENT_ALL = 0xFFFFFFFF,
    THREADEVENT_KERN = 0xFFFFFFF8,
    THREADEVENT_USER = 0xFFFFFFF0,
    THREADEVENT_CURRENT = 0
};

enum ThreadEvents
{
    THREAD_CREATE = 1,
    THREAD_START = 2,
    THREAD_EXIT = 4,
    THREAD_DELETE = 8,
};

struct PspDebugProfilerRegs
{
    volatile u32 enable;
    volatile u32 systemck;
    volatile u32 cpuck;
    volatile u32 internal;
    volatile u32 memory;
    volatile u32 copz;
    volatile u32 vfpu;
    volatile u32 sleep;
    volatile u32 bus_access;
    volatile u32 uncached_load;
    volatile u32 uncached_store;
    volatile u32 cached_load;
    volatile u32 cached_store;
    volatile u32 i_miss;
    volatile u32 d_miss;
    volatile u32 d_writeback;
    volatile u32 cop0_inst;
    volatile u32 fpu_inst;
    volatile u32 vfpu_inst;
    volatile u32 local_bus;
};

SceUID sceKernelRegisterThreadEventHandler(const char *name, SceUID threadID, int mask, SceKernelThreadEventHandler handler, void *common);
int sceKernelReleaseThreadEventHandler(SceUID uid);
int sceKernelReferThreadEventHandlerStatus(SceUID uid, struct SceKernelThreadEventHandlerInfo *info);
PspDebugProfilerRegs *sceKernelReferThreadProfiler(void);
PspDebugProfilerRegs *sceKernelReferGlobalProfiler(void);

typedef long int __time_t;
typedef long int __suseconds_t;
typedef __suseconds_t suseconds_t;
typedef unsigned long time_t;
typedef unsigned long clock_t;

struct timezone
{
    int tz_minuteswest;
    int tz_dsttime;
};

struct tm
{
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

struct timeval
{
    __time_t tv_sec;
    __suseconds_t tv_usec;
};

time_t sceKernelLibcTime(time_t *t);
clock_t sceKernelLibcClock(void);
int sceKernelLibcGettimeofday(struct timeval *tp, struct timezone *tzp);
void sceKernelDcacheWritebackAll(void);
void sceKernelDcacheWritebackInvalidateAll(void);
void sceKernelDcacheWritebackRange(const void *p, unsigned int size);
void sceKernelDcacheWritebackInvalidateRange(const void *p, unsigned int size);
void sceKernelDcacheInvalidateRange(const void *p, unsigned int size);
void sceKernelIcacheInvalidateAll(void);
void sceKernelIcacheInvalidateRange(const void *p, unsigned int size);

struct SceKernelUtilsMt19937Context {
    unsigned int count;
    unsigned int state[624];
};

int sceKernelUtilsMt19937Init(SceKernelUtilsMt19937Context *ctx, u32 seed);
u32 sceKernelUtilsMt19937UInt(SceKernelUtilsMt19937Context *ctx);

struct SceKernelUtilsMd5Context {
    unsigned int h[4];
    unsigned int pad;
    SceUShort16 usRemains;
    SceUShort16 usComputed;
    SceULong64 ullTotalLen;
    unsigned char buf[64];
};

int sceKernelUtilsMd5Digest(u8 *data, u32 size, u8 *digest);
int sceKernelUtilsMd5BlockInit(SceKernelUtilsMd5Context *ctx);
int sceKernelUtilsMd5BlockUpdate(SceKernelUtilsMd5Context *ctx, u8 *data, u32 size);
int sceKernelUtilsMd5BlockResult(SceKernelUtilsMd5Context *ctx, u8 *digest);

struct SceKernelUtilsSha1Context {
    unsigned int h[5];
    SceUShort16 usRemains;
    SceUShort16 usComputed;
    SceULong64 ullTotalLen;
    unsigned char buf[64];
};

enum PspKernelErrorCodes
{
    SCE_KERNEL_ERROR_OK = 0,
    SCE_KERNEL_ERROR_ERROR = 0x80020001,
    SCE_KERNEL_ERROR_NOTIMP = 0x80020002,
    SCE_KERNEL_ERROR_ILLEGAL_EXPCODE = 0x80020032,
    SCE_KERNEL_ERROR_EXPHANDLER_NOUSE = 0x80020033,
    SCE_KERNEL_ERROR_EXPHANDLER_USED = 0x80020034,
    SCE_KERNEL_ERROR_SYCALLTABLE_NOUSED = 0x80020035,
    SCE_KERNEL_ERROR_SYCALLTABLE_USED = 0x80020036,
    SCE_KERNEL_ERROR_ILLEGAL_SYSCALLTABLE = 0x80020037,
    SCE_KERNEL_ERROR_ILLEGAL_PRIMARY_SYSCALL_NUMBER = 0x80020038,
    SCE_KERNEL_ERROR_PRIMARY_SYSCALL_NUMBER_INUSE = 0x80020039,
    SCE_KERNEL_ERROR_ILLEGAL_CONTEXT = 0x80020064,
    SCE_KERNEL_ERROR_ILLEGAL_INTRCODE = 0x80020065,
    SCE_KERNEL_ERROR_CPUDI = 0x80020066,
    SCE_KERNEL_ERROR_FOUND_HANDLER = 0x80020067,
    SCE_KERNEL_ERROR_NOTFOUND_HANDLER = 0x80020068,
    SCE_KERNEL_ERROR_ILLEGAL_INTRLEVEL = 0x80020069,
    SCE_KERNEL_ERROR_ILLEGAL_ADDRESS = 0x8002006a,
    SCE_KERNEL_ERROR_ILLEGAL_INTRPARAM = 0x8002006b,
    SCE_KERNEL_ERROR_ILLEGAL_STACK_ADDRESS = 0x8002006c,
    SCE_KERNEL_ERROR_ALREADY_STACK_SET = 0x8002006d,
    SCE_KERNEL_ERROR_NO_TIMER = 0x80020096,
    SCE_KERNEL_ERROR_ILLEGAL_TIMERID = 0x80020097,
    SCE_KERNEL_ERROR_ILLEGAL_SOURCE = 0x80020098,
    SCE_KERNEL_ERROR_ILLEGAL_PRESCALE = 0x80020099,
    SCE_KERNEL_ERROR_TIMER_BUSY = 0x8002009a,
    SCE_KERNEL_ERROR_TIMER_NOT_SETUP = 0x8002009b,
    SCE_KERNEL_ERROR_TIMER_NOT_INUSE = 0x8002009c,
    SCE_KERNEL_ERROR_UNIT_USED = 0x800200a0,
    SCE_KERNEL_ERROR_UNIT_NOUSE = 0x800200a1,
    SCE_KERNEL_ERROR_NO_ROMDIR = 0x800200a2,
    SCE_KERNEL_ERROR_IDTYPE_EXIST = 0x800200c8,
    SCE_KERNEL_ERROR_IDTYPE_NOT_EXIST = 0x800200c9,
    SCE_KERNEL_ERROR_IDTYPE_NOT_EMPTY = 0x800200ca,
    SCE_KERNEL_ERROR_UNKNOWN_UID = 0x800200cb,
    SCE_KERNEL_ERROR_UNMATCH_UID_TYPE = 0x800200cc,
    SCE_KERNEL_ERROR_ID_NOT_EXIST = 0x800200cd,
    SCE_KERNEL_ERROR_NOT_FOUND_UIDFUNC = 0x800200ce,
    SCE_KERNEL_ERROR_UID_ALREADY_HOLDER = 0x800200cf,
    SCE_KERNEL_ERROR_UID_NOT_HOLDER = 0x800200d0,
    SCE_KERNEL_ERROR_ILLEGAL_PERM = 0x800200d1,
    SCE_KERNEL_ERROR_ILLEGAL_ARGUMENT = 0x800200d2,
    SCE_KERNEL_ERROR_ILLEGAL_ADDR = 0x800200d3,
    SCE_KERNEL_ERROR_OUT_OF_RANGE = 0x800200d4,
    SCE_KERNEL_ERROR_MEM_RANGE_OVERLAP = 0x800200d5,
    SCE_KERNEL_ERROR_ILLEGAL_PARTITION = 0x800200d6,
    SCE_KERNEL_ERROR_PARTITION_INUSE = 0x800200d7,
    SCE_KERNEL_ERROR_ILLEGAL_MEMBLOCKTYPE = 0x800200d8,
    SCE_KERNEL_ERROR_MEMBLOCK_ALLOC_FAILED = 0x800200d9,
    SCE_KERNEL_ERROR_MEMBLOCK_RESIZE_LOCKED = 0x800200da,
    SCE_KERNEL_ERROR_MEMBLOCK_RESIZE_FAILED = 0x800200db,
    SCE_KERNEL_ERROR_HEAPBLOCK_ALLOC_FAILED = 0x800200dc,
    SCE_KERNEL_ERROR_HEAP_ALLOC_FAILED = 0x800200dd,
    SCE_KERNEL_ERROR_ILLEGAL_CHUNK_ID = 0x800200de,
    SCE_KERNEL_ERROR_NOCHUNK = 0x800200df,
    SCE_KERNEL_ERROR_NO_FREECHUNK = 0x800200e0,
    SCE_KERNEL_ERROR_LINKERR = 0x8002012c,
    SCE_KERNEL_ERROR_ILLEGAL_OBJECT = 0x8002012d,
    SCE_KERNEL_ERROR_UNKNOWN_MODULE = 0x8002012e,
    SCE_KERNEL_ERROR_NOFILE = 0x8002012f,
    SCE_KERNEL_ERROR_FILEERR = 0x80020130,
    SCE_KERNEL_ERROR_MEMINUSE = 0x80020131,
    SCE_KERNEL_ERROR_PARTITION_MISMATCH = 0x80020132,
    SCE_KERNEL_ERROR_ALREADY_STARTED = 0x80020133,
    SCE_KERNEL_ERROR_NOT_STARTED = 0x80020134,
    SCE_KERNEL_ERROR_ALREADY_STOPPED = 0x80020135,
    SCE_KERNEL_ERROR_CAN_NOT_STOP = 0x80020136,
    SCE_KERNEL_ERROR_NOT_STOPPED = 0x80020137,
    SCE_KERNEL_ERROR_NOT_REMOVABLE = 0x80020138,
    SCE_KERNEL_ERROR_EXCLUSIVE_LOAD = 0x80020139,
    SCE_KERNEL_ERROR_LIBRARY_NOT_YET_LINKED = 0x8002013a,
    SCE_KERNEL_ERROR_LIBRARY_FOUND = 0x8002013b,
    SCE_KERNEL_ERROR_LIBRARY_NOTFOUND = 0x8002013c,
    SCE_KERNEL_ERROR_ILLEGAL_LIBRARY = 0x8002013d,
    SCE_KERNEL_ERROR_LIBRARY_INUSE = 0x8002013e,
    SCE_KERNEL_ERROR_ALREADY_STOPPING = 0x8002013f,
    SCE_KERNEL_ERROR_ILLEGAL_OFFSET = 0x80020140,
    SCE_KERNEL_ERROR_ILLEGAL_POSITION = 0x80020141,
    SCE_KERNEL_ERROR_ILLEGAL_ACCESS = 0x80020142,
    SCE_KERNEL_ERROR_MODULE_MGR_BUSY = 0x80020143,
    SCE_KERNEL_ERROR_ILLEGAL_FLAG = 0x80020144,
    SCE_KERNEL_ERROR_CANNOT_GET_MODULELIST = 0x80020145,
    SCE_KERNEL_ERROR_PROHIBIT_LOADMODULE_DEVICE = 0x80020146,
    SCE_KERNEL_ERROR_PROHIBIT_LOADEXEC_DEVICE = 0x80020147,
    SCE_KERNEL_ERROR_UNSUPPORTED_PRX_TYPE = 0x80020148,
    SCE_KERNEL_ERROR_ILLEGAL_PERM_CALL = 0x80020149,
    SCE_KERNEL_ERROR_CANNOT_GET_MODULE_INFORMATION = 0x8002014a,
    SCE_KERNEL_ERROR_ILLEGAL_LOADEXEC_BUFFER = 0x8002014b,
    SCE_KERNEL_ERROR_ILLEGAL_LOADEXEC_FILENAME = 0x8002014c,
    SCE_KERNEL_ERROR_NO_EXIT_CALLBACK = 0x8002014d,
    SCE_KERNEL_ERROR_NO_MEMORY = 0x80020190,
    SCE_KERNEL_ERROR_ILLEGAL_ATTR = 0x80020191,
    SCE_KERNEL_ERROR_ILLEGAL_ENTRY = 0x80020192,
    SCE_KERNEL_ERROR_ILLEGAL_PRIORITY = 0x80020193,
    SCE_KERNEL_ERROR_ILLEGAL_STACK_SIZE = 0x80020194,
    SCE_KERNEL_ERROR_ILLEGAL_MODE = 0x80020195,
    SCE_KERNEL_ERROR_ILLEGAL_MASK = 0x80020196,
    SCE_KERNEL_ERROR_ILLEGAL_THID = 0x80020197,
    SCE_KERNEL_ERROR_UNKNOWN_THID = 0x80020198,
    SCE_KERNEL_ERROR_UNKNOWN_SEMID = 0x80020199,
    SCE_KERNEL_ERROR_UNKNOWN_EVFID = 0x8002019a,
    SCE_KERNEL_ERROR_UNKNOWN_MBXID = 0x8002019b,
    SCE_KERNEL_ERROR_UNKNOWN_VPLID = 0x8002019c,
    SCE_KERNEL_ERROR_UNKNOWN_FPLID = 0x8002019d,
    SCE_KERNEL_ERROR_UNKNOWN_MPPID = 0x8002019e,
    SCE_KERNEL_ERROR_UNKNOWN_ALMID = 0x8002019f,
    SCE_KERNEL_ERROR_UNKNOWN_TEID = 0x800201a0,
    SCE_KERNEL_ERROR_UNKNOWN_CBID = 0x800201a1,
    SCE_KERNEL_ERROR_DORMANT = 0x800201a2,
    SCE_KERNEL_ERROR_SUSPEND = 0x800201a3,
    SCE_KERNEL_ERROR_NOT_DORMANT = 0x800201a4,
    SCE_KERNEL_ERROR_NOT_SUSPEND = 0x800201a5,
    SCE_KERNEL_ERROR_NOT_WAIT = 0x800201a6,
    SCE_KERNEL_ERROR_CAN_NOT_WAIT = 0x800201a7,
    SCE_KERNEL_ERROR_WAIT_TIMEOUT = 0x800201a8,
    SCE_KERNEL_ERROR_WAIT_CANCEL = 0x800201a9,
    SCE_KERNEL_ERROR_RELEASE_WAIT = 0x800201aa,
    SCE_KERNEL_ERROR_NOTIFY_CALLBACK = 0x800201ab,
    SCE_KERNEL_ERROR_THREAD_TERMINATED = 0x800201ac,
    SCE_KERNEL_ERROR_SEMA_ZERO = 0x800201ad,
    SCE_KERNEL_ERROR_SEMA_OVF = 0x800201ae,
    SCE_KERNEL_ERROR_EVF_COND = 0x800201af,
    SCE_KERNEL_ERROR_EVF_MULTI = 0x800201b0,
    SCE_KERNEL_ERROR_EVF_ILPAT = 0x800201b1,
    SCE_KERNEL_ERROR_MBOX_NOMSG = 0x800201b2,
    SCE_KERNEL_ERROR_MPP_FULL = 0x800201b3,
    SCE_KERNEL_ERROR_MPP_EMPTY = 0x800201b4,
    SCE_KERNEL_ERROR_WAIT_DELETE = 0x800201b5,
    SCE_KERNEL_ERROR_ILLEGAL_MEMBLOCK = 0x800201b6,
    SCE_KERNEL_ERROR_ILLEGAL_MEMSIZE = 0x800201b7,
    SCE_KERNEL_ERROR_ILLEGAL_SPADADDR = 0x800201b8,
    SCE_KERNEL_ERROR_SPAD_INUSE = 0x800201b9,
    SCE_KERNEL_ERROR_SPAD_NOT_INUSE = 0x800201ba,
    SCE_KERNEL_ERROR_ILLEGAL_TYPE = 0x800201bb,
    SCE_KERNEL_ERROR_ILLEGAL_SIZE = 0x800201bc,
    SCE_KERNEL_ERROR_ILLEGAL_COUNT = 0x800201bd,
    SCE_KERNEL_ERROR_UNKNOWN_VTID = 0x800201be,
    SCE_KERNEL_ERROR_ILLEGAL_VTID = 0x800201bf,
    SCE_KERNEL_ERROR_ILLEGAL_KTLSID = 0x800201c0,
    SCE_KERNEL_ERROR_KTLS_FULL = 0x800201c1,
    SCE_KERNEL_ERROR_KTLS_BUSY = 0x800201c2,
    SCE_KERNEL_ERROR_PM_INVALID_PRIORITY = 0x80020258,
    SCE_KERNEL_ERROR_PM_INVALID_DEVNAME = 0x80020259,
    SCE_KERNEL_ERROR_PM_UNKNOWN_DEVNAME = 0x8002025a,
    SCE_KERNEL_ERROR_PM_PMINFO_REGISTERED = 0x8002025b,
    SCE_KERNEL_ERROR_PM_PMINFO_UNREGISTERED = 0x8002025c,
    SCE_KERNEL_ERROR_PM_INVALID_MAJOR_STATE = 0x8002025d,
    SCE_KERNEL_ERROR_PM_INVALID_REQUEST = 0x8002025e,
    SCE_KERNEL_ERROR_PM_UNKNOWN_REQUEST = 0x8002025f,
    SCE_KERNEL_ERROR_PM_INVALID_UNIT = 0x80020260,
    SCE_KERNEL_ERROR_PM_CANNOT_CANCEL = 0x80020261,
    SCE_KERNEL_ERROR_PM_INVALID_PMINFO = 0x80020262,
    SCE_KERNEL_ERROR_PM_INVALID_ARGUMENT = 0x80020263,
    SCE_KERNEL_ERROR_PM_ALREADY_TARGET_PWRSTATE = 0x80020264,
    SCE_KERNEL_ERROR_PM_CHANGE_PWRSTATE_FAILED = 0x80020265,
    SCE_KERNEL_ERROR_PM_CANNOT_CHANGE_DEVPWR_STATE = 0x80020266,
    SCE_KERNEL_ERROR_PM_NO_SUPPORT_DEVPWR_STATE = 0x80020267,
    SCE_KERNEL_ERROR_DMAC_REQUEST_FAILED = 0x800202bc,
    SCE_KERNEL_ERROR_DMAC_REQUEST_DENIED = 0x800202bd,
    SCE_KERNEL_ERROR_DMAC_OP_QUEUED = 0x800202be,
    SCE_KERNEL_ERROR_DMAC_OP_NOT_QUEUED = 0x800202bf,
    SCE_KERNEL_ERROR_DMAC_OP_RUNNING = 0x800202c0,
    SCE_KERNEL_ERROR_DMAC_OP_NOT_ASSIGNED = 0x800202c1,
    SCE_KERNEL_ERROR_DMAC_OP_TIMEOUT = 0x800202c2,
    SCE_KERNEL_ERROR_DMAC_OP_FREED = 0x800202c3,
    SCE_KERNEL_ERROR_DMAC_OP_USED = 0x800202c4,
    SCE_KERNEL_ERROR_DMAC_OP_EMPTY = 0x800202c5,
    SCE_KERNEL_ERROR_DMAC_OP_ABORTED = 0x800202c6,
    SCE_KERNEL_ERROR_DMAC_OP_ERROR = 0x800202c7,
    SCE_KERNEL_ERROR_DMAC_CHANNEL_RESERVED = 0x800202c8,
    SCE_KERNEL_ERROR_DMAC_CHANNEL_EXCLUDED = 0x800202c9,
    SCE_KERNEL_ERROR_DMAC_PRIVILEGE_ADDRESS = 0x800202ca,
    SCE_KERNEL_ERROR_DMAC_NO_ENOUGHSPACE = 0x800202cb,
    SCE_KERNEL_ERROR_DMAC_CHANNEL_NOT_ASSIGNED = 0x800202cc,
    SCE_KERNEL_ERROR_DMAC_CHILD_OPERATION = 0x800202cd,
    SCE_KERNEL_ERROR_DMAC_TOO_MUCH_SIZE = 0x800202ce,
    SCE_KERNEL_ERROR_DMAC_INVALID_ARGUMENT = 0x800202cf,
    SCE_KERNEL_ERROR_MFILE = 0x80020320,
    SCE_KERNEL_ERROR_NODEV = 0x80020321,
    SCE_KERNEL_ERROR_XDEV = 0x80020322,
    SCE_KERNEL_ERROR_BADF = 0x80020323,
    SCE_KERNEL_ERROR_INVAL = 0x80020324,
    SCE_KERNEL_ERROR_UNSUP = 0x80020325,
    SCE_KERNEL_ERROR_ALIAS_USED = 0x80020326,
    SCE_KERNEL_ERROR_CANNOT_MOUNT = 0x80020327,
    SCE_KERNEL_ERROR_DRIVER_DELETED = 0x80020328,
    SCE_KERNEL_ERROR_ASYNC_BUSY = 0x80020329,
    SCE_KERNEL_ERROR_NOASYNC = 0x8002032a,
    SCE_KERNEL_ERROR_REGDEV = 0x8002032b,
    SCE_KERNEL_ERROR_NOCWD = 0x8002032c,
    SCE_KERNEL_ERROR_NAMETOOLONG = 0x8002032d,
    SCE_KERNEL_ERROR_NXIO = 0x800203e8,
    SCE_KERNEL_ERROR_IO = 0x800203e9,
    SCE_KERNEL_ERROR_NOMEM = 0x800203ea,
    SCE_KERNEL_ERROR_STDIO_NOT_OPENED = 0x800203eb,
    SCE_KERNEL_ERROR_CACHE_ALIGNMENT = 0x8002044c,
    SCE_KERNEL_ERROR_ERRORMAX = 0x8002044d,
};
int sceKernelUtilsSha1Digest(u8 *data, u32 size, u8 *digest);
int sceKernelUtilsSha1BlockInit(SceKernelUtilsSha1Context *ctx);
int sceKernelUtilsSha1BlockUpdate(SceKernelUtilsSha1Context *ctx, u8 *data, u32 size);
int sceKernelUtilsSha1BlockResult(SceKernelUtilsSha1Context *ctx, u8 *digest);

SceUID sceKernelStdin(void);
SceUID sceKernelStdout(void);
SceUID sceKernelStderr(void);

enum PspInterrupts
{
    PSP_GPIO_INT = 4,
    PSP_ATA_INT = 5,
    PSP_UMD_INT = 6,
    PSP_MSCM0_INT = 7,
    PSP_WLAN_INT = 8,
    PSP_AUDIO_INT = 10,
    PSP_I2C_INT = 12,
    PSP_SIRCS_INT = 14,
    PSP_SYSTIMER0_INT = 15,
    PSP_SYSTIMER1_INT = 16,
    PSP_SYSTIMER2_INT = 17,
    PSP_SYSTIMER3_INT = 18,
    PSP_THREAD0_INT = 19,
    PSP_NAND_INT = 20,
    PSP_DMACPLUS_INT = 21,
    PSP_DMA0_INT = 22,
    PSP_DMA1_INT = 23,
    PSP_MEMLMD_INT = 24,
    PSP_GE_INT = 25,
    PSP_VBLANK_INT = 30,
    PSP_MECODEC_INT = 31,
    PSP_HPREMOTE_INT = 36,
    PSP_MSCM1_INT = 60,
    PSP_MSCM2_INT = 61,
    PSP_THREAD1_INT = 65,
    PSP_INTERRUPT_INT = 66
};

unsigned int sceKernelCpuSuspendIntr(void);
void sceKernelCpuResumeIntr(unsigned int flags);
void sceKernelCpuResumeIntrWithSync(unsigned int flags);
int sceKernelIsCpuIntrSuspended(unsigned int flags);
int sceKernelIsCpuIntrEnable(void);
int sceKernelRegisterSubIntrHandler(int intno, int no, void *handler, void *arg);
int sceKernelReleaseSubIntrHandler(int intno, int no);
int sceKernelEnableSubIntr(int intno, int no);
int sceKernelDisableSubIntr(int intno, int no);

struct PspIntrHandlerOptionParam
{
    int size;
    u32 entry;
    u32 common;
    u32 gp;
    u16 intr_code;
    u16 sub_count;
    u16 intr_level;
    u16 enabled;
    u32 calls;
    u32 field_1C;
    u32 total_clock_lo;
    u32 total_clock_hi;
    u32 min_clock_lo;
    u32 min_clock_hi;
    u32 max_clock_lo;
    u32 max_clock_hi;
};

struct PspIoDrv;

struct PspIoDrvArg
{
    struct PspIoDrv *drv;
    void *arg;
};

struct PspIoDrvFileArg
{
    u32 unk1;
    u32 fs_num;
    PspIoDrvArg *drv;
    u32 unk2;
    void *arg;
};

struct PspIoDrvFuncs
{
    int (*IoInit)(PspIoDrvArg* arg);
    int (*IoExit)(PspIoDrvArg* arg);
    int (*IoOpen)(PspIoDrvFileArg *arg, char *file, int flags, SceMode mode);
    int (*IoClose)(PspIoDrvFileArg *arg);
    int (*IoRead)(PspIoDrvFileArg *arg, char *data, int len);
    int (*IoWrite)(PspIoDrvFileArg *arg, const char *data, int len);
    SceOff (*IoLseek)(PspIoDrvFileArg *arg, SceOff ofs, int whence);
    int (*IoIoctl)(PspIoDrvFileArg *arg, unsigned int cmd, void *indata, int inlen, void *outdata, int outlen);
    int (*IoRemove)(PspIoDrvFileArg *arg, const char *name);
    int (*IoMkdir)(PspIoDrvFileArg *arg, const char *name, SceMode mode);
    int (*IoRmdir)(PspIoDrvFileArg *arg, const char *name);
    int (*IoDopen)(PspIoDrvFileArg *arg, const char *dirname);
    int (*IoDclose)(PspIoDrvFileArg *arg);
    int (*IoDread)(PspIoDrvFileArg *arg, SceIoDirent *dir);
    int (*IoGetstat)(PspIoDrvFileArg *arg, const char *file, SceIoStat *stat);
    int (*IoChstat)(PspIoDrvFileArg *arg, const char *file, SceIoStat *stat, int bits);
    int (*IoRename)(PspIoDrvFileArg *arg, const char *oldname, const char *newname);
    int (*IoChdir)(PspIoDrvFileArg *arg, const char *dir);
    int (*IoMount)(PspIoDrvFileArg *arg);
    int (*IoUmount)(PspIoDrvFileArg *arg);
    int (*IoDevctl)(PspIoDrvFileArg *arg, const char *devname, unsigned int cmd, void *indata, int inlen, void *outdata, int outlen);
    int (*IoUnk21)(PspIoDrvFileArg *arg);
};

struct PspIoDrv
{
    const char *name;
    u32 dev_type;
    u32 unk2;
    const char *name2;
    PspIoDrvFuncs *funcs;
};

int sceIoAddDrv(PspIoDrv *drv);
int sceIoDelDrv(const char *drv_name);
int sceIoReopen(const char *file, int flags, SceMode mode, SceUID fd);
int sceIoGetThreadCwd(SceUID uid, char *dir, int len);
int sceIoChangeThreadCwd(SceUID uid, char *dir);

struct SceModule __packed {
    struct SceModule *next;
    unsigned short attribute;
    unsigned char version[2];
    char modname[27];
    char terminal;
    unsigned int unknown1;
    unsigned int unknown2;
    SceUID modid;
    unsigned int unknown3[4];
    void * ent_top;
    unsigned int ent_size;
    void * stub_top;
    unsigned int stub_size;
    unsigned int unknown4[4];
    unsigned int entry_addr;
    unsigned int gp_value;
    unsigned int text_addr;
    unsigned int text_size;
    unsigned int data_size;
    unsigned int bss_size;
    unsigned int nsegment;
    unsigned int segmentaddr[4];
    unsigned int segmentsize[4];
};

struct SceLibraryEntryTable {
    const char * libname;
    unsigned char version[2];
    unsigned short attribute;
    unsigned char len;
    unsigned char vstubcount;
    unsigned short stubcount;
    void * entrytable;
};

struct SceLibraryStubTable {
    const char * libname;
    unsigned char version[2];
    unsigned short attribute;
    unsigned char len;
    unsigned char vstubcount;
    unsigned short stubcount;
    unsigned int * nidtable;
    void * stubtable;
    void * vstubtable;
};

typedef void (*PspDebugPutChar)(unsigned short* args, unsigned int ch);

void sceKernelRegisterDebugPutchar(PspDebugPutChar func);
PspDebugPutChar sceKernelGetDebugPutchar(void);
SceModule * sceKernelFindModuleByName(const char *modname);
SceModule * sceKernelFindModuleByAddress(unsigned int addr);
SceModule * sceKernelFindModuleByUID(SceUID modid);
int sceKernelModuleCount(void);
void sceKernelIcacheClearAll(void);
int sceKernelStdoutReopen(const char *file, int flags, SceMode mode);
int sceKernelStderrReopen(const char *file, int flags, SceMode mode);
int fdprintf(int fd, const char *format, ...);
int sceSysregMeResetEnable(void);
int sceSysregMeResetDisable(void);
int sceSysregVmeResetEnable(void);
int sceSysregVmeResetDisable(void);
int sceSysregMeBusClockEnable(void);
int sceSysregMeBusClockDisable(void);
int sceSysconGetTachyonVersion( int* version );

int sceKernelRegisterIntrHandler(int intno, int no, void *handler, void *arg1, void *arg2);
int sceKernelReleaseIntrHandler(int intno);
int sceKernelEnableIntr(int intno);
int sceKernelDisableIntr(int intno);
int sceKernelIsIntrContext(void);
int sceKernelGetModuleList(int readbufsize, SceUID *readbuf);
int sceKernelModuleCount(void);
SceUID sceKernelLoadModuleBuffer(void *buf, SceSize bufsize, int flags, SceKernelLMOption *option);

struct PspGeContext {
    unsigned int context[512];
};

struct SceGeStack
{
    unsigned int stack[8];
};

typedef void (*PspGeCallback)(int id, void *arg);

struct PspGeCallbackData
{
    PspGeCallback signal_func;
    void *signal_arg;
    PspGeCallback finish_func;
    void *finish_arg;
};

struct PspGeListArgs
{
    unsigned int size;
    PspGeContext* context;
    u32 numStacks;
    SceGeStack *stacks;
};

struct PspGeBreakParam {
    unsigned int buf[4];
};

unsigned int sceGeEdramGetSize(void);
void * sceGeEdramGetAddr(void);
unsigned int sceGeGetCmd(int cmd);

enum PspGeMatrixTypes {
    PSP_GE_MATRIX_BONE0 = 0,
    PSP_GE_MATRIX_BONE1,
    PSP_GE_MATRIX_BONE2,
    PSP_GE_MATRIX_BONE3,
    PSP_GE_MATRIX_BONE4,
    PSP_GE_MATRIX_BONE5,
    PSP_GE_MATRIX_BONE6,
    PSP_GE_MATRIX_BONE7,
    PSP_GE_MATRIX_WORLD,
    PSP_GE_MATRIX_VIEW,
    PSP_GE_MATRIX_PROJECTION,
    PSP_GE_MATRIX_TEXGEN
};

int sceGeGetMtx(int type, void *matrix);

struct PspGeStack
{
    unsigned int stack[8];
};

int sceGeGetStack(int stackId, PspGeStack *stack);
int sceGeSaveContext(PspGeContext *context);
int sceGeRestoreContext(const PspGeContext *context);
int sceGeListEnQueue(const void *list, void *stall, int cbid, PspGeListArgs *arg);
int sceGeListEnQueueHead(const void *list, void *stall, int cbid, PspGeListArgs *arg);
int sceGeListDeQueue(int qid);
int sceGeListUpdateStallAddr(int qid, void *stall);

enum PspGeListState {
    PSP_GE_LIST_DONE = 0,
    PSP_GE_LIST_QUEUED,
    PSP_GE_LIST_DRAWING_DONE,
    PSP_GE_LIST_STALL_REACHED,
    PSP_GE_LIST_CANCEL_DONE
};

int sceGeListSync(int qid, int syncType);
int sceGeDrawSync(int syncType);
int sceGeSetCallback(PspGeCallbackData *cb);
int sceGeUnsetCallback(int cbid);
int sceGeBreak(int mode, PspGeBreakParam *pParam);
int sceGeContinue(void);
int sceGeEdramSetAddrTranslation(int width);

typedef void (*GuSwapBuffersCallback)(void** display,void** render);

void sceGuDepthBuffer(void* zbp, int zbw);
void sceGuDispBuffer(int width, int height, void* dispbp, int dispbw);
void sceGuDrawBuffer(int psm, void* fbp, int fbw);
void sceGuDrawBufferList(int psm, void* fbp, int fbw);
int sceGuDisplay(int state);
void sceGuDepthFunc(int function);
void sceGuDepthMask(int mask);
void sceGuDepthOffset(unsigned int offset);
void sceGuDepthRange(int near, int far);
void sceGuFog(float near, float far, unsigned int color);
void sceGuInit(void);
void sceGuTerm(void);
void sceGuBreak(int brk);
void sceGuContinue(void);
void* sceGuSetCallback(int signal, void (*callback)(int));
void sceGuSignal(int signal, int behavior);
void sceGuSendCommandf(int cmd, float argument);
void sceGuSendCommandi(int cmd, int argument);
void* sceGuGetMemory(int size);
void sceGuStart(int cid, void* list);
int sceGuFinish(void);
int sceGuFinishId(unsigned int id);
void sceGuCallList(const void* list);
void sceGuCallMode(int mode);
int sceGuCheckList(void);
void sceGuSendList(int mode, const void* list, PspGeContext* context);
void* sceGuSwapBuffers(void);
int sceGuSync(int mode, int what);
void sceGuDrawArray(int prim, int vtype, int count, const void* indices, const void* vertices);
void sceGuBeginObject(int vtype, int count, const void* indices, const void* vertices);
void sceGuEndObject(void);
void sceGuSetStatus(int state, int status);
int sceGuGetStatus(int state);
void sceGuSetAllStatus(int status);
int sceGuGetAllStatus(void);
void sceGuEnable(int state);
void sceGuDisable(int state);
void sceGuLight(int light, int type, int components, const ScePspFVector3* position);
void sceGuLightAtt(int light, float atten0, float atten1, float atten2);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuLightMode(int mode);
void sceGuLightSpot(int light, const ScePspFVector3* direction, float exponent, float cutoff);
void sceGuClear(int flags);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuPixelMask(unsigned int mask);
void sceGuColor(unsigned int color);
void sceGuColorFunc(int func, unsigned int color, unsigned int mask);
void sceGuColorMaterial(int components);
void sceGuAlphaFunc(int func, int value, int mask);
void sceGuAmbient(unsigned int color);
void sceGuAmbientColor(unsigned int color);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuMaterial(int mode, int color);
void sceGuModelColor(unsigned int emissive, unsigned int ambient, unsigned int diffuse, unsigned int specular);
void sceGuStencilFunc(int func, int ref, int mask);
void sceGuStencilOp(int fail, int zfail, int zpass);
void sceGuSpecular(float power);
void sceGuFrontFace(int order);
void sceGuLogicalOp(int op);
void sceGuSetDither(const ScePspIMatrix4* matrix);
void sceGuShadeModel(int mode);
void sceGuCopyImage(int psm, int sx, int sy, int width, int height, int srcw, void* src, int dx, int dy, int destw, void* dest);
void sceGuTexEnvColor(unsigned int color);
void sceGuTexFilter(int min, int mag);
void sceGuTexFlush(void);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void* tbp);
void sceGuTexLevelMode(unsigned int mode, float bias);
void sceGuTexMapMode(int mode, unsigned int five, unsigned int six);
void sceGuTexMode(int tpsm, int maxmips, int six, int swizzle);
void sceGuTexOffset(float u, float v);
void sceGuTexProjMapMode(int mode);
void sceGuTexScale(float u, float v);
void sceGuTexSlope(float slope);
void sceGuTexSync();
void sceGuTexWrap(int u, int v);
void sceGuClutLoad(int num_blocks, const void* cbp);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int seven);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuScissor(int x, int y, int w, int h);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGuDrawBezier(int vtype, int ucount, int vcount, const void* indices, const void* vertices);
void sceGuPatchDivide(unsigned int ulevel, unsigned int vlevel);
void sceGuPatchFrontFace(unsigned int four);
void sceGuPatchPrim(int prim);
void sceGuDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void* indices, const void* vertices);
void sceGuSetMatrix(int type, const ScePspFMatrix4* matrix);
void sceGuBoneMatrix(unsigned int index, const ScePspFMatrix4* matrix);
void sceGuMorphWeight(int index, float weight);
void sceGuDrawArrayN(int primitive_type, int vertex_type, int count, int seven, const void* indices, const void* vertices);
void guSwapBuffersBehaviour(int behaviour);
void guSwapBuffersCallback(GuSwapBuffersCallback callback);

typedef void (*GuCallback)(int);

struct GuSettings
{
    GuCallback sig;
    GuCallback fin;
    short signal_history[16];
    int signal_offset;
    int kernel_event_flag;
    int ge_callback_id;
    GuSwapBuffersCallback swapBuffersCallback;
    int swapBuffersBehaviour;
};

struct GuDisplayList
{
    unsigned int* start;
    unsigned int* current;
    int parent_context;
};

struct GuContext
{
    GuDisplayList list;
    int scissor_enable;
    int scissor_start[2];
    int scissor_end[2];
    int near_plane;
    int far_plane;
    int depth_offset;
    int fragment_2x;
    int texture_function;
    int texture_proj_map_mode;
    int texture_map_mode;
    int sprite_mode[4];
    unsigned int clear_color;
    unsigned int clear_stencil;
    unsigned int clear_depth;
    int texture_mode;
};

struct GuDrawBuffer
{
    int pixel_size;
    int frame_width;
    void* frame_buffer;
    void* disp_buffer;
    void* depth_buffer;
    int depth_width;
    int width;
    int height;
};

struct GuLightSettings
{
    unsigned char enable;
    unsigned char type;
    unsigned char xpos;
    unsigned char ypos;
    unsigned char zpos;
    unsigned char xdir;
    unsigned char ydir;
    unsigned char zdir;
    unsigned char ambient;
    unsigned char diffuse;
    unsigned char specular;
    unsigned char constant;
    unsigned char linear;
    unsigned char quadratic;
    unsigned char exponent;
    unsigned char cutoff;
};

int sceWlanDevIsPowerOn(void);
int sceWlanGetSwitchState(void);
int sceWlanGetEtherAddr(u8 *etherAddr);
int sceWlanDevAttach(void);
int sceWlanDevDetach(void);

struct pspTime {
    u16 year;
    u16 month;
    u16 day;
    u16 hour;
    u16 minutes;
    u16 seconds;
    u32 microseconds;
};

enum pspRtcCheckValidErrors {
    PSP_TIME_INVALID_YEAR = -1,
    PSP_TIME_INVALID_MONTH = -2,
    PSP_TIME_INVALID_DAY = -3,
    PSP_TIME_INVALID_HOUR = -4,
    PSP_TIME_INVALID_MINUTES = -5,
    PSP_TIME_INVALID_SECONDS = -6,
    PSP_TIME_INVALID_MICROSECONDS = -7
};

u32 sceRtcGetTickResolution();
int sceRtcGetCurrentTick(u64 *tick);
int sceRtcGetCurrentClock(pspTime *time, int tz);
int sceRtcGetCurrentClockLocalTime(pspTime *time);
int sceRtcConvertUtcToLocalTime(const u64* tickUTC, u64* tickLocal);
int sceRtcConvertLocalTimeToUTC(const u64* tickLocal, u64* tickUTC);
int sceRtcIsLeapYear(int year);
int sceRtcGetDaysInMonth(int year, int month);
int sceRtcGetDayOfWeek(int year, int month, int day);
int sceRtcCheckValid(const pspTime* date);
int sceRtcSetTick(pspTime* date, const u64* tick);
int sceRtcGetTick(const pspTime* date, u64 *tick);
int sceRtcCompareTick(const u64* tick1, const u64* tick2);
int sceRtcTickAddTicks(u64* destTick, const u64* srcTick, u64 numTicks);
int sceRtcTickAddMicroseconds(u64* destTick, const u64* srcTick, u64 numMS);
int sceRtcTickAddSeconds(u64* destTick, const u64* srcTick, u64 numSecs);
int sceRtcTickAddMinutes(u64* destTick, const u64* srcTick, u64 numMins);
int sceRtcTickAddHours(u64* destTick, const u64* srcTick, int numHours);
int sceRtcTickAddDays(u64* destTick, const u64* srcTick, int numDays);
int sceRtcTickAddWeeks(u64* destTick, const u64* srcTick, int numWeeks);
int sceRtcTickAddMonths(u64* destTick, const u64* srcTick, int numMonths);
int sceRtcTickAddYears(u64* destTick, const u64* srcTick, int numYears);
int sceRtcSetTime_t(pspTime* date, const time_t time);
int sceRtcGetTime_t(const pspTime* date, time_t *time);
int sceRtcSetDosTime(pspTime* date, u32 dosTime);
int sceRtcGetDosTime(pspTime* date, u32 dosTime);
int sceRtcSetWin32FileTime(pspTime* date, u64* win32Time);
int sceRtcGetWin32FileTime(pspTime* date, u64* win32Time);
int sceRtcParseDateTime(u64 *destTick, const char *dateString);
int sceRtcFormatRFC2822(char *pszDateTime, const u64 *pUtc, int iTimeZoneMinutes);
int sceRtcFormatRFC2822LocalTime(char *pszDateTime, const u64 *pUtc);
int sceRtcFormatRFC3339(char *pszDateTime, const u64 *pUtc, int iTimeZoneMinutes);
int sceRtcFormatRFC3339LocalTime(char *pszDateTime, const u64 *pUtc);
int sceRtcParseRFC3339(u64 *pUtc, const char *pszDateTime);

struct sircs_data __packed {
    u8 type;
    u8 cmd;
    u16 dev;
};

int sceSircsSend(struct sircs_data* sd, int count);

enum PspUsbCamResolution
{
    PSP_USBCAM_RESOLUTION_160_120 = 0,
    PSP_USBCAM_RESOLUTION_176_144 = 1,
    PSP_USBCAM_RESOLUTION_320_240 = 2,
    PSP_USBCAM_RESOLUTION_352_288 = 3,
    PSP_USBCAM_RESOLUTION_640_480 = 4,
    PSP_USBCAM_RESOLUTION_1024_768 = 5,
    PSP_USBCAM_RESOLUTION_1280_960 = 6,
    PSP_USBCAM_RESOLUTION_480_272 = 7,
    PSP_USBCAM_RESOLUTION_360_272 = 8,
};

enum PspUsbCamResolutionEx
{
    PSP_USBCAM_RESOLUTION_EX_160_120 = 0,
    PSP_USBCAM_RESOLUTION_EX_176_144 = 1,
    PSP_USBCAM_RESOLUTION_EX_320_240 = 2,
    PSP_USBCAM_RESOLUTION_EX_352_288 = 3,
    PSP_USBCAM_RESOLUTION_EX_360_272 = 4,
    PSP_USBCAM_RESOLUTION_EX_480_272 = 5,
    PSP_USBCAM_RESOLUTION_EX_640_480 = 6,
    PSP_USBCAM_RESOLUTION_EX_1024_768 = 7,
    PSP_USBCAM_RESOLUTION_EX_1280_960 = 8,
};

enum PspUsbCamReverseFlags
{
    PSP_USBCAM_FLIP = 1,
    PSP_USBCAM_MIRROR = 0x100,
};

enum PspUsbCamDelay
{
    PSP_USBCAM_NODELAY = 0,
    PSP_USBCAM_DELAY_10SEC = 1,
    PSP_USBCAM_DELAY_20SEC = 2,
    PSP_USBCAM_DELAY_30SEC = 3,
};

enum PspUsbCamFrameRate
{
    PSP_USBCAM_FRAMERATE_3_75_FPS = 0,
    PSP_USBCAM_FRAMERATE_5_FPS = 1,
    PSP_USBCAM_FRAMERATE_7_5_FPS = 2,
    PSP_USBCAM_FRAMERATE_10_FPS = 3,
    PSP_USBCAM_FRAMERATE_15_FPS = 4,
    PSP_USBCAM_FRAMERATE_20_FPS = 5,
    PSP_USBCAM_FRAMERATE_30_FPS = 6,
    PSP_USBCAM_FRAMERATE_60_FPS = 7,
};

enum PspUsbCamWB
{
    PSP_USBCAM_WB_AUTO = 0,
    PSP_USBCAM_WB_DAYLIGHT = 1,
    PSP_USBCAM_WB_FLUORESCENT = 2,
    PSP_USBCAM_WB_INCADESCENT = 3,
};

enum PspUsbCamEffectMode
{
    PSP_USBCAM_EFFECTMODE_NORMAL = 0,
    PSP_USBCAM_EFFECTMODE_NEGATIVE = 1,
    PSP_USBCAM_EFFECTMODE_BLACKWHITE = 2,
    PSP_USBCAM_EFFECTMODE_SEPIA = 3,
    PSP_USBCAM_EFFECTMODE_BLUE = 4,
    PSP_USBCAM_EFFECTMODE_RED = 5,
    PSP_USBCAM_EFFECTMODE_GREEN = 6,
};

enum PspUsbCamEVLevel
{
    PSP_USBCAM_EVLEVEL_2_0_POSITIVE = 0,
    PSP_USBCAM_EVLEVEL_1_7_POSITIVE = 1,
    PSP_USBCAM_EVLEVEL_1_5_POSITIVE = 2,
    PSP_USBCAM_EVLEVEL_1_3_POSITIVE = 3,
    PSP_USBCAM_EVLEVEL_1_0_POSITIVE = 4,
    PSP_USBCAM_EVLEVEL_0_7_POSITIVE = 5,
    PSP_USBCAM_EVLEVEL_0_5_POSITIVE = 6,
    PSP_USBCAM_EVLEVEL_0_3_POSITIVE = 7,
    PSP_USBCAM_EVLEVEL_0_0 = 8,
    PSP_USBCAM_EVLEVEL_0_3_NEGATIVE = 9,
    PSP_USBCAM_EVLEVEL_0_5_NEGATIVE = 10,
    PSP_USBCAM_EVLEVEL_0_7_NEGATIVE = 11,
    PSP_USBCAM_EVLEVEL_1_0_NEGATIVE = 12,
    PSP_USBCAM_EVLEVEL_1_3_NEGATIVE = 13,
    PSP_USBCAM_EVLEVEL_1_5_NEGATIVE = 14,
    PSP_USBCAM_EVLEVEL_1_7_NEGATIVE = 15,
    PSP_USBCAM_EVLEVEL_2_0_NEGATIVE = 16,
};

struct PspUsbCamSetupStillParam {
    int size;
    int resolution;
    int jpegsize;
    int reverseflags;
    int delay;
    int complevel;
};

struct PspUsbCamSetupStillExParam {
    int size;
    u32 unk;
    int resolution;
    int jpegsize;
    int complevel;
    u32 unk2;
    u32 unk3;
    int flip;
    int mirror;
    int delay;
    u32 unk4[5];
};

struct PspUsbCamSetupVideoParam {
    int size;
    int resolution;
    int framerate;
    int wb;
    int saturation;
    int brightness;
    int contrast;
    int sharpness;
    int effectmode;
    int framesize;
    u32 unk;
    int evlevel;
};

struct PspUsbCamSetupVideoExParam {
    int size;
    u32 unk;
    int resolution;
    int framerate;
    u32 unk2;
    u32 unk3;
    int wb;
    int saturation;
    int brightness;
    int contrast;
    int sharpness;
    u32 unk4;
    u32 unk5;
    u32 unk6[3];
    int effectmode;
    u32 unk7;
    u32 unk8;
    u32 unk9;
    u32 unk10;
    u32 unk11;
    int framesize;
    u32 unk12;
    int evlevel;
};

int sceUsbCamSetupStill(PspUsbCamSetupStillParam *param);
int sceUsbCamSetupStillEx(PspUsbCamSetupStillExParam *param);
int sceUsbCamStillInputBlocking(u8 *buf, SceSize size);
int sceUsbCamStillInput(u8 *buf, SceSize size);
int sceUsbCamStillWaitInputEnd(void);
int sceUsbCamStillPollInputEnd(void);
int sceUsbCamStillCancelInput(void);
int sceUsbCamStillGetInputLength(void);
int sceUsbCamSetupVideo(PspUsbCamSetupVideoParam *param, void *workarea, int wasize);
int sceUsbCamSetupVideoEx(PspUsbCamSetupVideoExParam *param, void *workarea, int wasize);
int sceUsbCamStartVideo(void);
int sceUsbCamStopVideo(void);
int sceUsbCamReadVideoFrameBlocking(u8 *buf, SceSize size);
int sceUsbCamReadVideoFrame(u8 *buf, SceSize size);
int sceUsbCamWaitReadVideoFrameEnd(void);
int sceUsbCamPollReadVideoFrameEnd(void);
int sceUsbCamGetReadVideoFrameSize(void);
int sceUsbCamSetSaturation(int saturation);
int sceUsbCamSetBrightness(int brightness);
int sceUsbCamSetContrast(int contrast);
int sceUsbCamSetSharpness(int sharpness);
int sceUsbCamSetImageEffectMode(int effectmode);
int sceUsbCamSetEvLevel(int ev);
int sceUsbCamSetReverseMode(int reverseflags);
int sceUsbCamSetZoom(int zoom);
int sceUsbCamGetSaturation(int *saturation);
int sceUsbCamGetBrightness(int *brightness);
int sceUsbCamGetContrast(int *contrast);
int sceUsbCamGetSharpness(int *sharpness);
int sceUsbCamGetImageEffectMode(int *effectmode);
int sceUsbCamGetEvLevel(int *ev);
int sceUsbCamGetReverseMode(int *reverseflags);
int sceUsbCamGetZoom(int *zoom);
int sceUsbCamAutoImageReverseSW(int on);
int sceUsbCamGetAutoImageReverseState(void);
int sceUsbCamGetLensDirection(void);

struct UsbInterface
{
    int expect_interface;
    int unk8;
    int num_interface;
};

struct UsbEndpoint
{
    int endpnum;
    int unk2;
    int unk3;
};

struct StringDescriptor __packed
{
    unsigned char bLength;
    unsigned char bDescriptorType;
    short bString[32];
};

struct DeviceDescriptor __packed
{
    unsigned char bLength;
    unsigned char bDescriptorType;
    unsigned short bcdUSB;
    unsigned char bDeviceClass;
    unsigned char bDeviceSubClass;
    unsigned char bDeviceProtocol;
    unsigned char bMaxPacketSize;
    unsigned short idVendor;
    unsigned short idProduct;
    unsigned short bcdDevice;
    unsigned char iManufacturer;
    unsigned char iProduct;
    unsigned char iSerialNumber;
    unsigned char bNumConfigurations;
};

struct ConfigDescriptor __packed
{
    unsigned char bLength;
    unsigned char bDescriptorType;
    unsigned short wTotalLength;
    unsigned char bNumInterfaces;
    unsigned char bConfigurationValue;
    unsigned char iConfiguration;
    unsigned char bmAttributes;
    unsigned char bMaxPower;
};

struct InterfaceDescriptor __packed
{
    unsigned char bLength;
    unsigned char bDescriptorType;
    unsigned char bInterfaceNumber;
    unsigned char bAlternateSetting;
    unsigned char bNumEndpoints;
    unsigned char bInterfaceClass;
    unsigned char bInterfaceSubClass;
    unsigned char bInterfaceProtocol;
    unsigned char iInterface;
};


struct EndpointDescriptor __packed
{
    unsigned char bLength;
    unsigned char bDescriptorType;
    unsigned char bEndpointAddress;
    unsigned char bmAttributes;
    unsigned short wMaxPacketSize;
    unsigned char bInterval;
};

struct UsbInterfaces
{
    struct InterfaceDescriptor *infp[2];
    unsigned int num;
};

struct UsbConfiguration
{
    struct ConfigDescriptor *confp;
    struct UsbInterfaces *infs;
    struct InterfaceDescriptor *infp;
    struct EndpointDescriptor *endp;
};

struct UsbDataConfig __packed
{
    void *pconfdesc;
    void *pinterfaces;
    void *pinterdesc;
    void *pendp;
};

struct UsbDataConfDesc __packed
{
    unsigned char desc[12];
    void *pinterfaces;
};

struct UsbDataInterfaces __packed
{
    void *pinterdesc[2];
    unsigned int intcount;
};

struct UsbDataInterDesc __packed
{
    unsigned char desc[12];
    void *pendp;
    unsigned char pad[32];
};

struct UsbDataEndp __packed
{
    unsigned char desc[16];
};

struct UsbData __packed
{
    unsigned char devdesc[20];
    UsbDataConfig config;
    UsbDataConfDesc confdesc;
    unsigned char pad1[8];
    UsbDataInterfaces interfaces;
    UsbDataInterDesc interdesc;
    UsbDataEndp endp[4];
};

struct DeviceRequest __packed
{
    unsigned char bmRequestType;
    unsigned char bRequest;
    unsigned short wValue;
    unsigned short wIndex;
    unsigned short wLength;
};

struct UsbDriver
{
    const char *name;
    int endpoints;
    struct UsbEndpoint *endp;
    struct UsbInterface *intp;
    void *devp_hi;
    void *confp_hi;
    void *devp;
    void *confp;
    struct StringDescriptor *str;
    int (*recvctl)(int arg1, int arg2, struct DeviceRequest *req);
    int (*func28)(int arg1, int arg2, int arg3);
    int (*attach)(int speed, void *arg2, void *arg3);
    int (*detach)(int arg1, int arg2, int arg3);
    int unk34;
    int (*start_func)(int size, void *args);
    int (*stop_func)(int size, void *args);
    struct UsbDriver *link;
};

struct UsbdDeviceReq
{
    struct UsbEndpoint *endp;
    void *data;
    int size;
    int unkc;
    void *func;
    int recvsize;
    int retcode;
    int unk1c;
    void *arg;
    void *link;
};

int sceUsbbdRegister(struct UsbDriver *drv);
int sceUsbbdUnregister(struct UsbDriver *drv);
int sceUsbbdClearFIFO(struct UsbEndpoint *endp);
int sceUsbbdReqCancelAll(struct UsbEndpoint *endp);
int sceUsbbdStall(struct UsbEndpoint *endp);
int sceUsbbdReqSend(struct UsbdDeviceReq *req);
int sceUsbbdReqRecv(struct UsbdDeviceReq *req);
int sceUsbStart(const char* driverName, int size, void *args);
int sceUsbStop(const char* driverName, int size, void *args);
int sceUsbActivate(u32 pid);
int sceUsbDeactivate(u32 pid);
int sceUsbGetState(void);
int sceUsbGetDrvState(const char* driverName);

union netData {
    u32 asUint;
    char asString[128];
};

int sceUtilityCheckNetParam(int id);
int sceUtilityGetNetParam(int conf, int param, netData *data);
int sceUtilityCreateNetParam(int conf);
int sceUtilitySetNetParam(int param, const void *val);
int sceUtilityCopyNetParam(int src, int dest);
int sceUtilityDeleteNetParam(int conf);
int sceUtilityLoadNetModule(int module);
int sceUtilityUnloadNetModule(int module);
int sceUtilitySetSystemParamInt(int id, int value);
int sceUtilitySetSystemParamString(int id, const char *str);
int sceUtilityGetSystemParamInt( int id, int *value );
int sceUtilityGetSystemParamString(int id, char *str, int len);

enum PspUtilitySavedataMode
{
    PSP_UTILITY_SAVEDATA_AUTOLOAD = 0,
    PSP_UTILITY_SAVEDATA_AUTOSAVE,
    PSP_UTILITY_SAVEDATA_LOAD,
    PSP_UTILITY_SAVEDATA_SAVE,
    PSP_UTILITY_SAVEDATA_LISTLOAD,
    PSP_UTILITY_SAVEDATA_LISTSAVE,
    PSP_UTILITY_SAVEDATA_LISTDELETE,
    PSP_UTILITY_SAVEDATADELETE,

};

enum PspUtilitySavedataFocus
{
    PSP_UTILITY_SAVEDATA_FOCUS_UNKNOWN = 0,
    PSP_UTILITY_SAVEDATA_FOCUS_FIRSTLIST,
    PSP_UTILITY_SAVEDATA_FOCUS_LASTLIST,
    PSP_UTILITY_SAVEDATA_FOCUS_LATEST,
    PSP_UTILITY_SAVEDATA_FOCUS_OLDEST,
    PSP_UTILITY_SAVEDATA_FOCUS_UNKNOWN2,
    PSP_UTILITY_SAVEDATA_FOCUS_UNKNOWN3,
    PSP_UTILITY_SAVEDATA_FOCUS_FIRSTEMPTY,
    PSP_UTILITY_SAVEDATA_FOCUS_LASTEMPTY,

};

struct PspUtilitySavedataSFOParam
{
    char title[0x80];
    char savedataTitle[0x80];
    char detail[0x400];
    unsigned char parentalLevel;
    unsigned char unknown[3];
};

struct PspUtilitySavedataFileData {
    void *buf;
    SceSize bufSize;
    SceSize size;
    int unknown;
};

struct PspUtilitySavedataListSaveNewData
{
    PspUtilitySavedataFileData icon0;
    char *title;
};

struct pspUtilityDialogCommon
{
    unsigned int size;
    int language;
    int buttonSwap;
    int graphicsThread;
    int accessThread;
    int fontThread;
    int soundThread;
    int result;
    int reserved[4];

};

struct SceUtilitySavedataParam
{
    pspUtilityDialogCommon base;
    PspUtilitySavedataMode mode;
    int unknown1;
    int overwrite;
    char gameName[13];
    char reserved[3];
    char saveName[20];
    char *saveNameList[20];
    char fileName[13];
    char reserved1[3];
    void *dataBuf;
    SceSize dataBufSize;
    SceSize dataSize;
    PspUtilitySavedataSFOParam sfoParam;
    PspUtilitySavedataFileData icon0FileData;
    PspUtilitySavedataFileData icon1FileData;
    PspUtilitySavedataFileData pic1FileData;
    PspUtilitySavedataFileData snd0FileData;
    PspUtilitySavedataListSaveNewData *newData;
    PspUtilitySavedataFocus focus;
    int unknown2[4];
};

int sceUtilitySavedataInitStart(SceUtilitySavedataParam * params);
int sceUtilitySavedataGetStatus(void);
int sceUtilitySavedataShutdownStart(void);
void sceUtilitySavedataUpdate(int unknown);

enum pspUtilityMsgDialogMode
{
    PSP_UTILITY_MSGDIALOG_MODE_ERROR = 0,
    PSP_UTILITY_MSGDIALOG_MODE_TEXT

};

enum pspUtilityMsgDialogOption
{
    PSP_UTILITY_MSGDIALOG_OPTION_ERROR = 0,
    PSP_UTILITY_MSGDIALOG_OPTION_TEXT = 0x00000001,
    PSP_UTILITY_MSGDIALOG_OPTION_YESNO_BUTTONS = 0x00000010,
    PSP_UTILITY_MSGDIALOG_OPTION_DEFAULT_NO = 0x00000100

};

enum pspUtilityMsgDialogPressed
{
    PSP_UTILITY_MSGDIALOG_RESULT_UNKNOWN1 = 0,
    PSP_UTILITY_MSGDIALOG_RESULT_YES,
    PSP_UTILITY_MSGDIALOG_RESULT_NO,
    PSP_UTILITY_MSGDIALOG_RESULT_BACK

};

struct pspUtilityMsgDialogParams
{
    pspUtilityDialogCommon base;
    int unknown;
    pspUtilityMsgDialogMode mode;
    unsigned int errorValue;
    char message[512];
    int options;
    pspUtilityMsgDialogPressed buttonPressed;
};

int sceUtilityMsgDialogInitStart(pspUtilityMsgDialogParams *params);
void sceUtilityMsgDialogShutdownStart(void);
int sceUtilityMsgDialogGetStatus(void);
void sceUtilityMsgDialogUpdate(int n);
int sceUtilityMsgDialogAbort(void);

enum pspUtilityNetconfActions
{
    PSP_NETCONF_ACTION_CONNECTAP,
    PSP_NETCONF_ACTION_DISPLAYSTATUS,
    PSP_NETCONF_ACTION_CONNECT_ADHOC
};

struct pspUtilityNetconfAdhoc
{
    unsigned char name[8];
    unsigned int timeout;
};

struct pspUtilityNetconfData
{
    pspUtilityDialogCommon base;
    int action;
    struct pspUtilityNetconfAdhoc *adhocparam;
    int hotspot;
    int hotspot_connected;
    int wifisp;
};

int sceUtilityNetconfInitStart (pspUtilityNetconfData *data);
int sceUtilityNetconfShutdownStart (void);
int sceUtilityNetconfUpdate (int unknown);
int sceUtilityNetconfGetStatus (void);

enum pspUtilityGameSharingMode
{
    PSP_UTILITY_GAMESHARING_MODE_SINGLE = 1,
    PSP_UTILITY_GAMESHARING_MODE_MULTIPLE = 2

};

enum pspUtilityGameSharingDataType
{
    PSP_UTILITY_GAMESHARING_DATA_TYPE_FILE = 1,
    PSP_UTILITY_GAMESHARING_DATA_TYPE_MEMORY = 2,
};

struct pspUtilityGameSharingParams
{
    pspUtilityDialogCommon base;
    int unknown1;
    int unknown2;
    char name[8];
    int unknown3;
    int unknown4;
    int unknown5;
    int result;
    char *filepath;
    pspUtilityGameSharingMode mode;
    pspUtilityGameSharingDataType datatype;
    void *data;
    unsigned int datasize;
};

int sceUtilityGameSharingInitStart(pspUtilityGameSharingParams *params);
void sceUtilityGameSharingShutdownStart(void);
int sceUtilityGameSharingGetStatus(void);
void sceUtilityGameSharingUpdate(int n);

enum pspUtilityHtmlViewerDisconnectModes
{
    PSP_UTILITY_HTMLVIEWER_DISCONNECTMODE_ENABLE = 0,
    PSP_UTILITY_HTMLVIEWER_DISCONNECTMODE_DISABLE,
    PSP_UTILITY_HTMLVIEWER_DISCONNECTMODE_CONFIRM
};

enum pspUtilityHtmlViewerInterfaceModes
{
    PSP_UTILITY_HTMLVIEWER_INTERFACEMODE_FULL = 0,
    PSP_UTILITY_HTMLVIEWER_INTERFACEMODE_LIMITED,
    PSP_UTILITY_HTMLVIEWER_INTERFACEMODE_NONE
};

enum pspUtilityHtmlViewerCookieModes
{
    PSP_UTILITY_HTMLVIEWER_COOKIEMODE_DISABLED = 0,
    PSP_UTILITY_HTMLVIEWER_COOKIEMODE_ENABLED,
    PSP_UTILITY_HTMLVIEWER_COOKIEMODE_CONFIRM,
    PSP_UTILITY_HTMLVIEWER_COOKIEMODE_DEFAULT
};

enum pspUtilityHtmlViewerTextSizes
{
    PSP_UTILITY_HTMLVIEWER_TEXTSIZE_LARGE = 0,
    PSP_UTILITY_HTMLVIEWER_TEXTSIZE_NORMAL,
    PSP_UTILITY_HTMLVIEWER_TEXTSIZE_SMALL
};

enum pspUtilityHtmlViewerDisplayModes
{
    PSP_UTILITY_HTMLVIEWER_DISPLAYMODE_NORMAL = 0,
    PSP_UTILITY_HTMLVIEWER_DISPLAYMODE_FIT,
    PSP_UTILITY_HTMLVIEWER_DISPLAYMODE_SMART_FIT
};

enum pspUtilityHtmlViewerConnectModes
{
    PSP_UTILITY_HTMLVIEWER_CONNECTMODE_LAST = 0,
    PSP_UTILITY_HTMLVIEWER_CONNECTMODE_MANUAL_ONCE,
    PSP_UTILITY_HTMLVIEWER_CONNECTMODE_MANUAL_ALL
};

enum pspUtilityHtmlViewerOptions
{
    PSP_UTILITY_HTMLVIEWER_OPEN_SCE_START_PAGE = 0x000001,
    PSP_UTILITY_HTMLVIEWER_DISABLE_STARTUP_LIMITS = 0x000002,
    PSP_UTILITY_HTMLVIEWER_DISABLE_EXIT_DIALOG = 0x000004,
    PSP_UTILITY_HTMLVIEWER_DISABLE_CURSOR = 0x000008,
    PSP_UTILITY_HTMLVIEWER_DISABLE_DOWNLOAD_COMPLETE_DIALOG = 0x000010,
    PSP_UTILITY_HTMLVIEWER_DISABLE_DOWNLOAD_START_DIALOG = 0x000020,
    PSP_UTILITY_HTMLVIEWER_DISABLE_DOWNLOAD_DESTINATION_DIALOG = 0x000040,
    PSP_UTILITY_HTMLVIEWER_LOCK_DOWNLOAD_DESTINATION_DIALOG = 0x000080,
    PSP_UTILITY_HTMLVIEWER_DISABLE_TAB_DISPLAY = 0x000100,
    PSP_UTILITY_HTMLVIEWER_ENABLE_ANALOG_HOLD = 0x000200,
    PSP_UTILITY_HTMLVIEWER_ENABLE_FLASH = 0x000400,
    PSP_UTILITY_HTMLVIEWER_DISABLE_LRTRIGGER = 0x000800
};

struct pspUtilityHtmlViewerParam
{
    pspUtilityDialogCommon base;
    void* memaddr;
    unsigned int memsize;
    int unknown1;
    int unknown2;
    char* initialurl;
    unsigned int numtabs;
    unsigned int interfacemode;
    unsigned int options;
    char* dldirname;
    char* dlfilename;
    char* uldirname;
    char* ulfilename;
    unsigned int cookiemode;
    unsigned int unknown3;
    char* homeurl;
    unsigned int textsize;
    unsigned int displaymode;
    unsigned int connectmode;
    unsigned int disconnectmode;
    unsigned int memused;
    int unknown4[10];
};

int sceUtilityHtmlViewerInitStart(pspUtilityHtmlViewerParam *params);
int sceUtilityHtmlViewerShutdownStart(void);
int sceUtilityHtmlViewerUpdate(int n);
int sceUtilityHtmlViewerGetStatus(void);

enum SceUtilityOskInputLanguage
{
    PSP_UTILITY_OSK_LANGUAGE_DEFAULT = 0x00,
    PSP_UTILITY_OSK_LANGUAGE_JAPANESE = 0x01,
    PSP_UTILITY_OSK_LANGUAGE_ENGLISH = 0x02,
    PSP_UTILITY_OSK_LANGUAGE_FRENCH = 0x03,
    PSP_UTILITY_OSK_LANGUAGE_SPANISH = 0x04,
    PSP_UTILITY_OSK_LANGUAGE_GERMAN = 0x05,
    PSP_UTILITY_OSK_LANGUAGE_ITALIAN = 0x06,
    PSP_UTILITY_OSK_LANGUAGE_DUTCH = 0x07,
    PSP_UTILITY_OSK_LANGUAGE_PORTUGESE = 0x08,
    PSP_UTILITY_OSK_LANGUAGE_RUSSIAN = 0x09,
    PSP_UTILITY_OSK_LANGUAGE_KOREAN = 0x0a
};

enum SceUtilityOskState
{
    PSP_UTILITY_OSK_DIALOG_NONE = 0,
    PSP_UTILITY_OSK_DIALOG_INITING,
    PSP_UTILITY_OSK_DIALOG_INITED,
    PSP_UTILITY_OSK_DIALOG_VISIBLE,
    PSP_UTILITY_OSK_DIALOG_QUIT,
    PSP_UTILITY_OSK_DIALOG_FINISHED
};

enum SceUtilityOskResult
{
    PSP_UTILITY_OSK_RESULT_UNCHANGED = 0,
    PSP_UTILITY_OSK_RESULT_CANCELLED,
    PSP_UTILITY_OSK_RESULT_CHANGED
};

enum SceUtilityOskInputType
{
    PSP_UTILITY_OSK_INPUTTYPE_ALL = 0x00000000,
    PSP_UTILITY_OSK_INPUTTYPE_LATIN_DIGIT = 0x00000001,
    PSP_UTILITY_OSK_INPUTTYPE_LATIN_SYMBOL = 0x00000002,
    PSP_UTILITY_OSK_INPUTTYPE_LATIN_LOWERCASE = 0x00000004,
    PSP_UTILITY_OSK_INPUTTYPE_LATIN_UPPERCASE = 0x00000008,
    PSP_UTILITY_OSK_INPUTTYPE_JAPANESE_DIGIT = 0x00000100,
    PSP_UTILITY_OSK_INPUTTYPE_JAPANESE_SYMBOL = 0x00000200,
    PSP_UTILITY_OSK_INPUTTYPE_JAPANESE_LOWERCASE = 0x00000400,
    PSP_UTILITY_OSK_INPUTTYPE_JAPANESE_UPPERCASE = 0x00000800,
    PSP_UTILITY_OSK_INPUTTYPE_JAPANESE_HIRAGANA = 0x00001000,
    PSP_UTILITY_OSK_INPUTTYPE_JAPANESE_HALF_KATAKANA = 0x00002000,
    PSP_UTILITY_OSK_INPUTTYPE_JAPANESE_KATAKANA = 0x00004000,
    PSP_UTILITY_OSK_INPUTTYPE_JAPANESE_KANJI = 0x00008000,
    PSP_UTILITY_OSK_INPUTTYPE_RUSSIAN_LOWERCASE = 0x00010000,
    PSP_UTILITY_OSK_INPUTTYPE_RUSSIAN_UPPERCASE = 0x00020000,
    PSP_UTILITY_OSK_INPUTTYPE_KOREAN = 0x00040000,
    PSP_UTILITY_OSK_INPUTTYPE_URL = 0x00080000
};

struct SceUtilityOskData
{
    int unk_00;
    int unk_04;
    int language;
    int unk_12;
    int inputtype;
    int lines;
    int unk_24;
    unsigned short* desc;
    unsigned short* intext;
    int outtextlength;
    unsigned short* outtext;
    int result;
    int outtextlimit;
};

struct SceUtilityOskParams
{
    pspUtilityDialogCommon base;
    int datacount;
    SceUtilityOskData* data;
    int state;
    int unk_60;
};

int sceUtilityOskInitStart(SceUtilityOskParams* params);
int sceUtilityOskShutdownStart(void);
int sceUtilityOskUpdate(int n);
int sceUtilityOskGetStatus(void);
int sceUtilityLoadAvModule(int module);
int sceUtilityUnloadAvModule(int module);
int sceUtilityLoadUsbModule(int module);
int sceUtilityUnloadUsbModule(int module);
int sceUtilityLoadModule(int module);
int sceUtilityUnloadModule(int module);

enum pspUtilityDialogState
{
    PSP_UTILITY_DIALOG_NONE = 0,
    PSP_UTILITY_DIALOG_INIT,
    PSP_UTILITY_DIALOG_VISIBLE,
    PSP_UTILITY_DIALOG_QUIT,
    PSP_UTILITY_DIALOG_FINISHED

};

int sceNandSetWriteProtect(int protectFlag);
int sceNandLock(int writeFlag);
void sceNandUnlock(void);
int sceNandReadStatus(void);
int sceNandReset(int flag);
int sceNandReadId(void *buf, SceSize size);
int sceNandReadPages(u32 ppn, void *buf, void *buf2, u32 count);
int sceNandGetPageSize(void);
int sceNandGetPagesPerBlock(void);
int sceNandGetTotalBlocks(void);
int sceNandReadBlockWithRetry(u32 ppn, void *buf, void *buf2);
int sceNandIsBadBlock(u32 ppn);

struct PspOpenPSID
{
    unsigned char data[16];
};

int sceOpenPSIDGetOpenPSID(PspOpenPSID *openpsid);

struct _PspLibraryEntry {
    const char * name;
    unsigned short version;
    unsigned short attribute;
    unsigned char entLen;
    unsigned char varCount;
    unsigned short funcCount;
    void * entrytable;
};

int sceKernelVolatileMemLock(int unk, void **ptr, int *size);
int sceKernelVolatileMemTryLock(int unk, void **ptr, int *size);
int sceKernelVolatileMemUnlock(int unk);

typedef void (* pspAudioCallback_t)(void *buf, unsigned int reqn, void *pdata);

struct pspAudioInputParams
{
    int unknown1;
    int gain;
    int unknown2;
    int unknown3;
    int unknown4;
    int unknown5;
};

int sceAudioChReserve(int channel, int samplecount, int format);
int sceAudioChRelease(int channel);
int sceAudioOutput(int channel, int vol, void *buf);
int sceAudioOutputBlocking(int channel, int vol, void *buf);
int sceAudioOutputPanned(int channel, int leftvol, int rightvol, void *buf);
int sceAudioOutputPannedBlocking(int channel, int leftvol, int rightvol, void *buf);
int sceAudioGetChannelRestLen(int channel);
int sceAudioGetChannelRestLength(int channel);
int sceAudioSetChannelDataLen(int channel, int samplecount);
int sceAudioChangeChannelConfig(int channel, int format);
int sceAudioChangeChannelVolume(int channel, int leftvol, int rightvol);
int sceAudioOutput2Reserve(int samplecount);
int sceAudioOutput2Release(void);
int sceAudioOutput2ChangeLength(int samplecount);
int sceAudioOutput2OutputBlocking(int vol, void *buf);
int sceAudioOutput2GetRestSample(void);
int sceAudioSRCChReserve(int samplecount, int freq, int channels);
int sceAudioSRCChRelease(void);
int sceAudioSRCOutputBlocking(int vol, void *buf);
int sceAudioInputInit(int unknown1, int gain, int unknown2);
int sceAudioInputInitEx(pspAudioInputParams *params);
int sceAudioInputBlocking(int samplecount, int freq, void *buf);
int sceAudioInput(int samplecount, int freq, void *buf);
int sceAudioGetInputLength(void);
int sceAudioWaitInputEnd(void);
int sceAudioPollInputEnd(void);
int sceAudiocodecCheckNeedMem(unsigned long *Buffer, int Type);
int sceAudiocodecInit(unsigned long *Buffer, int Type);
int sceAudiocodecDecode(unsigned long *Buffer, int Type);
int sceAudiocodecGetEDRAM(unsigned long *Buffer, int Type);
int sceAudiocodecReleaseEDRAM(unsigned long *Buffer);
int sceUsbstorBootRegisterNotify(u32 eventFlag);
int sceUsbstorBootUnregisterNotify(u32 eventFlag);
int sceUsbstorBootSetCapacity(u32 size);
void sceCtrl_driver_7CA723DC(unsigned int mask, unsigned int type);
int sceCtrl_driver_5E77BC8A(unsigned int mask);
int sceCtrl_driver_5C56C779(int no, unsigned int mask, void (*cb)(int, int, void*), void *arg);

typedef int (*PspSysEventHandlerFunc)(int ev_id, char* ev_name, void* param, int* result);

struct PspSysEventHandler{
    int size;
    char* name;
    int type_mask;
    int (*handler)(int ev_id, char* ev_name, void* param, int* result);
    int r28;
    int busy;
    PspSysEventHandler *next;
    int reserved[9];
};

int sceKernelSysEventDispatch(int ev_type_mask, int ev_id, char* ev_name, void* param, int* result, int break_nonzero, PspSysEventHandler* break_handler);
PspSysEventHandler* sceKernelReferSysEventHandler(void);
int sceKernelIsRegisterSysEventHandler(PspSysEventHandler* handler);
int sceKernelRegisterSysEventHandler(PspSysEventHandler* handler);
int sceKernelUnregisterSysEventHandler(PspSysEventHandler* handler);

struct PspSysmemPartitionInfo
{
    SceSize size;
    unsigned int startaddr;
    unsigned int memsize;
    unsigned int attr;
};

int sceKernelQueryMemoryPartitionInfo(int pid, PspSysmemPartitionInfo *info);
SceSize sceKernelPartitionTotalFreeMemSize(int pid);
SceSize sceKernelPartitionMaxFreeMemSize(int pid);
void sceKernelSysMemDump(void);
void sceKernelSysMemDumpBlock(void);
void sceKernelSysMemDumpTail(void);
int sceKernelSetDdrMemoryProtection(void *addr, int size, int prot);
SceUID sceKernelCreateHeap(SceUID partitionid, SceSize size, int unk, const char *name);
void *sceKernelAllocHeapMemory(SceUID heapid, SceSize size);
int sceKernelFreeHeapMemory(SceUID heapid, void *block);
int sceKernelDeleteHeap(SceUID heapid);
SceSize sceKernelHeapTotalFreeSize(SceUID heapid);

struct uidControlBlock __packed
{
    struct uidControlBlock *parent;
    struct uidControlBlock *nextChild;
    struct uidControlBlock *type;
    u32 UID;
    char *name;
    unsigned char unk;
    unsigned char size;
    short attribute;
    struct uidControlBlock *nextEntry;
};

int sceKernelGetUIDcontrolBlock(SceUID uid, uidControlBlock** block);
int sceKernelGetUIDcontrolBlockWithType(SceUID uid, uidControlBlock* type, uidControlBlock** block);
uidControlBlock* SysMemForKernel_536AD5E1(void);
int sceKernelDeleteUID(SceUID uid);
int sceKernelGetModel(void);
int sceKernelSetCompiledSdkVersion(int version);
int sceKernelGetCompiledSdkVersion(void);
int sceAudioRoutingSetMode( int mode );
int sceAudioRoutingGetMode();

typedef int SceImposeParam;
int sceImposeGetParam(SceImposeParam param);
int sceImposeSetParam(SceImposeParam param, int value);
int sceImposeGetBacklightOffTime(void);
int sceImposeSetBacklightOffTime(int value);
int sceImposeGetLanguageMode(int* lang, int* button);
int sceImposeSetLanguageMode(int lang, int button);
int sceImposeGetUMDPopup(void);
int sceImposeSetUMDPopup(int value);
int sceImposeGetHomePopup(void);
int sceImposeSetHomePopup(int value);
int sceImposeCheckVideoOut(int* value);

enum PSPBootFrom
{
    PSP_BOOT_FLASH = 0,
    PSP_BOOT_DISC = 0x20,
    PSP_BOOT_MS = 0x40,
};

enum PSPInitApitype
{
    PSP_INIT_APITYPE_DISC = 0x120,
    PSP_INIT_APITYPE_DISC_UPDATER = 0x121,
    PSP_INIT_APITYPE_MS1 = 0x140,
    PSP_INIT_APITYPE_MS2 = 0x141,
    PSP_INIT_APITYPE_MS3 = 0x142,
    PSP_INIT_APITYPE_MS4 = 0x143,
    PSP_INIT_APITYPE_MS5 = 0x144,
    PSP_INIT_APITYPE_VSH1 = 0x210,
    PSP_INIT_APITYPE_VSH2 = 0x220,
};

enum PSPKeyConfig
{
    PSP_INIT_KEYCONFIG_VSH = 0x100,
    PSP_INIT_KEYCONFIG_GAME = 0x200,
    PSP_INIT_KEYCONFIG_POPS = 0x300,
};

int sceKernelInitApitype();
char *sceKernelInitFileName();
int sceKernelBootFrom();
int InitForKernel_7233B5BC();
int sceIdStorageLookup(u16 key, u32 offset, void *buf, u32 len);
int sceIdStorageReadLeaf(u16 key, void *buf);
int sceIdStorageWriteLeaf(u16 key, void *buf);
int sceIdStorageIsReadOnly(void);
int sceIdStorageFlush(void);

typedef int SceSysTimerId;

struct SceKernelLoadExecVSHParam {
    SceSize size;
    SceSize args;
    void * argp;
    const char * key;
    u32 vshmain_args_size;
    void *vshmain_args;
    char *configfile;
    u32 unk4;
    u32 unk5;
};

int sceKernelLoadExecBufferPlain(SceSize bufsize, void *buf, struct SceKernelLoadExecParam *param);
int sceKernelExitVSHVSH(struct SceKernelLoadExecVSHParam *param);
int sceKernelLoadExecVSHDisc(const char *file, struct SceKernelLoadExecVSHParam *param);
int sceKernelLoadExecVSHDiscUpdater(const char *file, struct SceKernelLoadExecVSHParam *param);
int sceKernelLoadExecVSHMs1(const char *file, struct SceKernelLoadExecVSHParam *param);
int sceKernelLoadExecVSHMs2(const char *file, struct SceKernelLoadExecVSHParam *param);
int sceKernelLoadExecVSHMs3(const char *file, struct SceKernelLoadExecVSHParam *param);
int sceKernelRegisterDefaultExceptionHandler(void *func);
int sceKernelRegisterExceptionHandler(int exno, void *func);
int sceKernelRegisterPriorityExceptionHandler(int exno, int priority, void *func);
int sceKernelGzipDecompress(u8 *dest, u32 destSize, const u8 *src, u32 unknown);
int sceKernelDeflateDecompress(u8 *dest, u32 destSize, const u8 *src, u32 unknown);
void sceKernelDcacheInvalidateAll(void);
int sceKernelDcacheProbe(void *addr);
void sceKernelIcacheInvalidateAll(void);
int sceKernelIcacheProbe(const void *addr);
void sceSysconPowerStandby(void);
void sceSysconResetDevice(int unk1, int unk2);
int sceSysconCtrlLED(int SceLED, int state);
int sceSysconCtrlHRPower(int power);
int sceSysconGetHPConnect(void);
int sceSysconSetHPConnectCallback( void (*)(int), int unk0 );
int sceSysconSetHRPowerCallback( void (*)(int), int unk0 );
int sceSysconGetPommelVersion( int* version );
int sceSysconGetBaryonVersion( int* version );
int sceKernelSuspendAllUserThreads(void);
int sceKernelIsUserModeThread(void);
int sceKernelGetUserLevel(void);
unsigned int sceKernelGetSyscallRA(void);
int sceKernelGetThreadKernelStackFreeSize(SceUID thid);
int sceKernelCheckThreadKernelStack(void);
int sceKernelExtendKernelStack(int type, void (*cb)(void*), void *arg);
unsigned int sceKernelGetSystemStatusFlag(void);
int sceKernelAllocateKTLS(int id, int (*cb)(unsigned int *size, void *arg), void *arg);
int sceKernelFreeKTLS(int id);
void *sceKernelGetKTLS(int id);
void *sceKernelGetThreadKTLS(int id, SceUID thid, int mode);

struct SceThreadContext {
    unsigned int type;
    unsigned int gpr[31];
    unsigned int fpr[32];
    unsigned int fc31;
    unsigned int hi;
    unsigned int lo;
    unsigned int SR;
    unsigned int EPC;
    unsigned int field_114;
    unsigned int field_118;
};

struct SceSCContext
{
    unsigned int status;
    unsigned int epc;
    unsigned int v29;
    unsigned int v31;
    unsigned int v27;
    unsigned int unk[3];
};

struct SceKernelThreadKInfo {
    SceSize size;
    char name[32];
    SceUInt attr;
    int status;
    SceKernelThreadEntry entry;
    void * stack;
    int stackSize;
    void * kstack;
    void * kstackSize;
    void * gpReg;
    SceSize args;
    void * argp;
    int initPriority;
    int currentPriority;
    int waitType;
    SceUID waitId;
    int wakeupCount;
    SceKernelSysClock runClocks;
    SceUInt intrPreemptCount;
    SceUInt threadPreemptCount;
    SceUInt releaseCount;
    struct SceThreadContext *thContext;
    float * vfpuContext;
    void * retAddr;
    SceUInt unknown1;
    struct SceSCContext *scContext;
};

int ThreadManForKernel_2D69D086(SceUID uid, SceKernelThreadKInfo *info);
void sceGumDrawArray(int prim, int vtype, int count, const void* indices, const void* vertices);
void sceGumDrawArrayN(int prim, int vtype, int count, int v7, const void* indices, const void* vertices);
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void* indices, const void* vertices);
void sceGumDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void* indices, const void* vertices);
void sceGumLoadIdentity(void);
void sceGumLoadMatrix(const ScePspFMatrix4* m);
void sceGumLookAt(ScePspFVector3* eye, ScePspFVector3* center, ScePspFVector3* up);
void sceGumMatrixMode(int mode);
void sceGumMultMatrix(const ScePspFMatrix4* m);
void sceGumOrtho(float left, float right, float bottom, float top, float near, float far);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumRotateXYZ(const ScePspFVector3* v);
void sceGumRotateZYX(const ScePspFVector3* v);
void sceGumScale(const ScePspFVector3* v);
void sceGumStoreMatrix(ScePspFMatrix4* m);
void sceGumTranslate(const ScePspFVector3* v);
void sceGumUpdateMatrix(void);
void sceGumFullInverse();
void sceGumFastInverse();
void sceGumBeginObject(int vtype, int count, const void* indices, const void* vertices);
void sceGumEndObject();

enum PspHttpHttpVersion
{
    PSP_HTTP_VERSION_1_0,
    PSP_HTTP_VERSION_1_1
};

enum PspHttpMethod
{
    PSP_HTTP_METHOD_GET,
    PSP_HTTP_METHOD_POST,
    PSP_HTTP_METHOD_HEAD

};

enum PspHttpAuthType
{
    PSP_HTTP_AUTH_BASIC,
    PSP_HTTP_AUTH_DIGEST
};

enum PspHttpProxyMode
{
    PSP_HTTP_PROXY_AUTO,
    PSP_HTTP_PROXY_MANUAL
};

enum PspHttpAddHeaderMode
{
    PSP_HTTP_HEADER_OVERWRITE,
    PSP_HTTP_HEADER_ADD
};

typedef void *(*PspHttpMallocFunction)(SceSize size);
typedef void *(*PspHttpReallocFunction)(void *p, SceSize size);
typedef void (*PspHttpFreeFunction)(void *p);

typedef int (*PspHttpPasswordCB)(
        int request,
        PspHttpAuthType auth_type,
        const unsigned char *realm,
        unsigned char *username,
        unsigned char *password,
        SceBool need_entity,
        unsigned char **entity_body,
        SceSize *entity_size,
        SceBool *save);

int sceHttpInit(unsigned int unknown1);
int sceHttpEnd(void);
int sceHttpCreateTemplate(char *agent, int unknown1, int unknown2);
int sceHttpDeleteTemplate(int templateid);
int sceHttpCreateConnection(int templateid, char *host, char *unknown1, unsigned short port, int unknown2);
int sceHttpCreateConnectionWithURL(int templateid, const char *url, int unknown1);
int sceHttpDeleteConnection(int connectionid);
int sceHttpCreateRequest(int connectionid, PspHttpMethod method, char *path, SceULong64 contentlength);
int sceHttpCreateRequestWithURL(int connectionid, PspHttpMethod method, char *url, SceULong64 contentlength);
int sceHttpDeleteRequest(int requestid);
int sceHttpSendRequest(int requestid, void *data, unsigned int datasize);
int sceHttpAbortRequest(int requestid);
int sceHttpReadData(int requestid, void *data, unsigned int datasize);
int sceHttpGetContentLength(int requestid, SceULong64 *contentlength);
int sceHttpGetStatusCode(int requestid, int *statuscode);
int sceHttpSetResolveTimeOut(int id, unsigned int timeout);
int sceHttpSetResolveRetry(int id, int count);
int sceHttpSetConnectTimeOut(int id, unsigned int timeout);
int sceHttpSetSendTimeOut(int id, unsigned int timeout);
int sceHttpSetRecvTimeOut(int id, unsigned int timeout);
int sceHttpEnableKeepAlive(int id);
int sceHttpDisableKeepAlive(int id);
int sceHttpEnableRedirect(int id);
int sceHttpDisableRedirect(int id);
int sceHttpEnableCookie(int id);
int sceHttpDisableCookie(int id);
int sceHttpSaveSystemCookie(void);
int sceHttpLoadSystemCookie(void);
int sceHttpAddExtraHeader(int id, char *name, char *value, int unknown1);
int sceHttpDeleteHeader(int id, const char *name);
int sceHttpsInit(int unknown1, int unknown2, int unknown3, int unknown4);
int sceHttpsEnd(void);
int sceHttpsLoadDefaultCert(int unknown1, int unknown2);
int sceHttpDisableAuth(int id);
int sceHttpDisableCache(int id);
int sceHttpEnableAuth(int id);
int sceHttpEnableCache(int id);
int sceHttpEndCache(void);
int sceHttpGetAllHeader(int request, unsigned char **header, unsigned int *header_size);
int sceHttpGetNetworkErrno(int request, int *err_num);
int sceHttpGetProxy(int id, int *activate_flag, int *mode, unsigned char *proxy_host, SceSize len, unsigned short *proxy_port);
int sceHttpInitCache(SceSize max_size);
int sceHttpSetAuthInfoCB(int id, PspHttpPasswordCB cbfunc);
int sceHttpSetProxy(int id, int activate_flag, int mode, const unsigned char *new_proxy_host, unsigned short new_proxy_port);
int sceHttpSetResHeaderMaxSize(int id, unsigned int header_size);
int sceHttpSetMallocFunction(PspHttpMallocFunction malloc_func, PspHttpFreeFunction free_func, PspHttpReallocFunction realloc_func);

typedef uint32_t in_addr_t;
struct in_addr
{
    in_addr_t s_addr;
};

int sceNetResolverInit(void);
int sceNetResolverCreate(int *rid, void *buf, SceSize buflen);
int sceNetResolverDelete(int rid);
int sceNetResolverStartNtoA(int rid, const char *hostname, struct in_addr* addr, unsigned int timeout, int retry);
int sceNetResolverStartAtoN(int rid, const struct in_addr* addr, char *hostname, SceSize hostname_len, unsigned int timeout, int retry);
int sceNetResolverStop(int rid);
int sceNetResolverTerm(void);

struct SceNetMallocStat
{
    int pool;
    int maximum;
    int free;

};

int sceNetInit(int poolsize, int calloutprio, int calloutstack, int netintrprio, int netintrstack);
int sceNetTerm(void);
int sceNetFreeThreadinfo(int thid);
int sceNetThreadAbort(int thid);
void sceNetEtherStrton(char *name, unsigned char *mac);
void sceNetEtherNtostr(unsigned char *mac, char *name);
int sceNetGetLocalEtherAddr(unsigned char *mac);
int sceNetGetMallocStat(SceNetMallocStat *stat);

int sceNetAdhocMatchingInit(int memsize);
int sceNetAdhocMatchingTerm(void);

struct pspAdhocPoolStat
{
    int size;
    int maxsize;
    int freesize;
};

typedef void (*pspAdhocMatchingCallback)(int matchingid, int event, unsigned char *mac, int optlen, void *optdata);

int sceNetAdhocMatchingCreate(int mode, int maxpeers, unsigned short port, int bufsize, unsigned int hellodelay, unsigned int pingdelay, int initcount, unsigned int msgdelay, pspAdhocMatchingCallback callback);
int sceNetAdhocMatchingDelete(int matchingid);
int sceNetAdhocMatchingStart(int matchingid, int evthpri, int evthstack, int inthpri, int inthstack, int optlen, void *optdata);
int sceNetAdhocMatchingStop(int matchingid);
int sceNetAdhocMatchingSelectTarget(int matchingid, unsigned char *mac, int optlen, void *optdata);
int sceNetAdhocMatchingCancelTarget(int matchingid, unsigned char *mac);
int sceNetAdhocMatchingCancelTargetWithOpt(int matchingid, unsigned char *mac, int optlen, void *optdata);
int sceNetAdhocMatchingSendData(int matchingid, unsigned char *mac, int datalen, void *data);
int sceNetAdhocMatchingAbortSendData(int matchingid, unsigned char *mac);
int sceNetAdhocMatchingSetHelloOpt(int matchingid, int optlen, void *optdata);
int sceNetAdhocMatchingGetHelloOpt(int matchingid, int *optlen, void *optdata);
int sceNetAdhocMatchingGetMembers(int matchingid, int *length, void *buf);
int sceNetAdhocMatchingGetPoolMaxAlloc(void);
int sceNetAdhocMatchingGetPoolStat(struct pspAdhocPoolStat *poolstat);
int sceNetAdhocInit(void);
int sceNetAdhocTerm(void);
int sceNetAdhocPdpCreate(unsigned char *mac, unsigned short port, unsigned int bufsize, int unk1);
int sceNetAdhocPdpDelete(int id, int unk1);
int sceNetAdhocPdpSend(int id, unsigned char *destMacAddr, unsigned short port, void *data, unsigned int len, unsigned int timeout, int nonblock);
int sceNetAdhocPdpRecv(int id, unsigned char *srcMacAddr, unsigned short *port, void *data, void *dataLength, unsigned int timeout, int nonblock);

struct pdpStatStruct
{

    struct pdpStatStruct *next;

    int pdpId;

    unsigned char mac[6];

    unsigned short port;

    unsigned int rcvdData;
};

int sceNetAdhocGetPdpStat(int *size, pdpStatStruct *stat);
int sceNetAdhocGameModeCreateMaster(void *data, int size);
int sceNetAdhocGameModeCreateReplica(unsigned char *mac, void *data, int size);
int sceNetAdhocGameModeUpdateMaster(void);
int sceNetAdhocGameModeUpdateReplica(int id, int unk1);
int sceNetAdhocGameModeDeleteMaster(void);
int sceNetAdhocGameModeDeleteReplica(int id);
int sceNetAdhocPtpOpen(unsigned char *srcmac, unsigned short srcport, unsigned char *destmac, unsigned short destport, unsigned int bufsize, unsigned int delay, int count, int unk1);
int sceNetAdhocPtpConnect(int id, unsigned int timeout, int nonblock);
int sceNetAdhocPtpListen(unsigned char *srcmac, unsigned short srcport, unsigned int bufsize, unsigned int delay, int count, int queue, int unk1);
int sceNetAdhocPtpAccept(int id, unsigned char *mac, unsigned short *port, unsigned int timeout, int nonblock);
int sceNetAdhocPtpSend(int id, void *data, int *datasize, unsigned int timeout, int nonblock);
int sceNetAdhocPtpRecv(int id, void *data, int *datasize, unsigned int timeout, int nonblock);
int sceNetAdhocPtpFlush(int id, unsigned int timeout, int nonblock);
int sceNetAdhocPtpClose(int id, int unk1);

struct ptpStatStruct
{
    struct ptpStatStruct *next;
    int ptpId;
    unsigned char mac[6];
    unsigned char peermac[6];
    unsigned short port;
    unsigned short peerport;
    unsigned int sentData;
    unsigned int rcvdData;
    int unk1;
};

int sceNetAdhocGetPtpStat(int *size, ptpStatStruct *stat);

struct productStruct
{
    int unknown;
    char product[9];
    char unk[3];
};


struct SceNetAdhocctlPeerInfo
{
    struct SceNetAdhocctlPeerInfo *next;
    char nickname[128];
    unsigned char mac[6];
    unsigned char unknown[6];
    unsigned long timestamp;
};


struct SceNetAdhocctlScanInfo
{
    struct SceNetAdhocctlScanInfo *next;
    int channel;
    char name[8];
    unsigned char bssid[6];
    unsigned char unknown[2];
    int unknown2;
};

struct SceNetAdhocctlGameModeInfo
{
    int count;
    unsigned char macs[96];
};


struct SceNetAdhocctlParams
{
    int channel;
    char name[8];
    unsigned char bssid[6];
    char nickname[128];
};

int sceNetAdhocctlInit(int stacksize, int priority, struct productStruct *product);
int sceNetAdhocctlTerm(void);
int sceNetAdhocctlConnect(const char *name);
int sceNetAdhocctlDisconnect(void);
int sceNetAdhocctlGetState(int *event);
int sceNetAdhocctlCreate(const char *name);
int sceNetAdhocctlJoin(struct SceNetAdhocctlScanInfo *scaninfo);
int sceNetAdhocctlGetAdhocId(struct productStruct *product);
int sceNetAdhocctlCreateEnterGameMode(const char *name, int unknown, int num, unsigned char *macs, unsigned int timeout, int unknown2);
int sceNetAdhocctlJoinEnterGameMode(const char *name, unsigned char *hostmac, unsigned int timeout, int unknown);
int sceNetAdhocctlGetGameModeInfo(struct SceNetAdhocctlGameModeInfo *gamemodeinfo);
int sceNetAdhocctlExitGameMode(void);
int sceNetAdhocctlGetPeerList(int *length, void *buf);
int sceNetAdhocctlGetPeerInfo(unsigned char *mac, int size, struct SceNetAdhocctlPeerInfo *peerinfo);
int sceNetAdhocctlScan(void);
int sceNetAdhocctlGetScanInfo(int *length, void *buf);

typedef void (*sceNetAdhocctlHandler)(int flag, int error, void *unknown);
int sceNetAdhocctlAddHandler(sceNetAdhocctlHandler handler, void *unknown);
int sceNetAdhocctlDelHandler(int id);
int sceNetAdhocctlGetNameByAddr(unsigned char *mac, char *nickname);
int sceNetAdhocctlGetAddrByName(char *nickname, int *length, void *buf);
int sceNetAdhocctlGetParameter(struct SceNetAdhocctlParams *params);
int sceNetInetInit(void);
int sceNetInetTerm(void);
int sceSslInit(int unknown1);
int sceSslEnd(void);
int sceSslGetUsedMemoryMax(unsigned int *memory);
int sceSslGetUsedMemoryCurrent(unsigned int *memory);

union SceNetApctlInfo
{
    char name[64];
    unsigned char bssid[6];
    unsigned char ssid[32];
    unsigned int ssidLength;
    unsigned int securityType;
    unsigned char strength;
    unsigned char channel;
    unsigned char powerSave;
    char ip[16];
    char subNetMask[16];
    char gateway[16];
    char primaryDns[16];
    char secondaryDns[16];
    unsigned int useProxy;
    char proxyUrl[128];
    unsigned short proxyPort;
    unsigned int eapType;
    unsigned int startBrowser;
    unsigned int wifisp;

};

typedef void (*sceNetApctlHandler)(int oldState, int newState, int event, int error, void *pArg);

int sceNetApctlInit(int stackSize, int initPriority);
int sceNetApctlTerm(void);
int sceNetApctlGetInfo(int code, union SceNetApctlInfo *pInfo);
int sceNetApctlAddHandler(sceNetApctlHandler handler, void *pArg);
int sceNetApctlDelHandler(int handlerId);
int sceNetApctlConnect(int connIndex);
int sceNetApctlDisconnect(void);
int sceNetApctlGetState(int *pState);

typedef ScePVoid SceMpeg;
typedef SceVoid SceMpegStream;
typedef SceInt32 (*sceMpegRingbufferCB)(ScePVoid pData, SceInt32 iNumPackets, ScePVoid pParam);

struct SceMpegRingbuffer
{
    SceInt32 iPackets;
    SceUInt32 iUnk0;
    SceUInt32 iUnk1;
    SceUInt32 iUnk2;
    SceUInt32 iUnk3;
    ScePVoid pData;
    sceMpegRingbufferCB Callback;
    ScePVoid pCBparam;
    SceUInt32 iUnk4;
    SceUInt32 iUnk5;
    SceMpeg pSceMpeg;
};

struct SceMpegAu
{
    SceUInt32 iPtsMSB;
    SceUInt32 iPts;
    SceUInt32 iDtsMSB;
    SceUInt32 iDts;
    SceUInt32 iEsBuffer;
    SceUInt32 iAuSize;
};

struct SceMpegAvcMode
{
    SceInt32 iUnk0;
    SceInt32 iPixelFormat;
};

SceInt32 sceMpegInit();
SceVoid sceMpegFinish();
SceInt32 sceMpegRingbufferQueryMemSize(SceInt32 iPackets);
SceInt32 sceMpegRingbufferConstruct(SceMpegRingbuffer* Ringbuffer, SceInt32 iPackets, ScePVoid pData, SceInt32 iSize, sceMpegRingbufferCB Callback, ScePVoid pCBparam);
SceVoid sceMpegRingbufferDestruct(SceMpegRingbuffer* Ringbuffer);
SceInt32 sceMpegRingbufferAvailableSize(SceMpegRingbuffer* Ringbuffer);
SceInt32 sceMpegRingbufferPut(SceMpegRingbuffer* Ringbuffer, SceInt32 iNumPackets, SceInt32 iAvailable);
SceInt32 sceMpegQueryMemSize(int iUnk);
SceInt32 sceMpegCreate(SceMpeg* Mpeg, ScePVoid pData, SceInt32 iSize, SceMpegRingbuffer* Ringbuffer, SceInt32 iFrameWidth, SceInt32 iUnk1, SceInt32 iUnk2);
SceVoid sceMpegDelete(SceMpeg* Mpeg);
SceInt32 sceMpegQueryStreamOffset(SceMpeg* Mpeg, ScePVoid pBuffer, SceInt32* iOffset);
SceInt32 sceMpegQueryStreamSize(ScePVoid pBuffer, SceInt32* iSize);
SceMpegStream* sceMpegRegistStream(SceMpeg* Mpeg, SceInt32 iStreamID, SceInt32 iUnk);
SceVoid sceMpegUnRegistStream(SceMpeg Mpeg, SceMpegStream* pStream);
SceInt32 sceMpegFlushAllStream(SceMpeg* Mpeg);
ScePVoid sceMpegMallocAvcEsBuf(SceMpeg* Mpeg);
SceVoid sceMpegFreeAvcEsBuf(SceMpeg* Mpeg, ScePVoid pBuf);
SceInt32 sceMpegQueryAtracEsSize(SceMpeg* Mpeg, SceInt32* iEsSize, SceInt32* iOutSize);
SceInt32 sceMpegInitAu(SceMpeg* Mpeg, ScePVoid pEsBuffer, SceMpegAu* pAu);
SceInt32 sceMpegGetAvcAu(SceMpeg* Mpeg, SceMpegStream* pStream, SceMpegAu* pAu, SceInt32* iUnk);
SceInt32 sceMpegAvcDecodeMode(SceMpeg* Mpeg, SceMpegAvcMode* pMode);
SceInt32 sceMpegAvcDecode(SceMpeg* Mpeg, SceMpegAu* pAu, SceInt32 iFrameWidth, ScePVoid pBuffer, SceInt32* iInit);
SceInt32 sceMpegAvcDecodeStop(SceMpeg* Mpeg, SceInt32 iFrameWidth, ScePVoid pBuffer, SceInt32* iStatus);
SceInt32 sceMpegGetAtracAu(SceMpeg* Mpeg, SceMpegStream* pStream, SceMpegAu* pAu, ScePVoid pUnk);
SceInt32 sceMpegAtracDecode(SceMpeg* Mpeg, SceMpegAu* pAu, ScePVoid pBuffer, SceInt32 iInit);
int sceJpegInitMJpeg(void);
int sceJpegFinishMJpeg(void);
int sceJpegCreateMJpeg(int width, int height);
int sceJpegDeleteMJpeg(void);
int sceJpegDecodeMJpeg(u8 *jpegbuf, SceSize size, void *rgba, u32 unk);

typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;

struct SceMpegLLI
{
    ScePVoid pSrc;
    ScePVoid pDst;
    ScePVoid Next;
    SceInt32 iSize;
};

struct SceMpegYCrCbBuffer
{
    SceInt32 iFrameBufferHeight16;
    SceInt32 iFrameBufferWidth16;
    SceInt32 iUnknown;
    SceInt32 iUnknown2;
    ScePVoid pYBuffer;
    ScePVoid pYBuffer2;
    ScePVoid pCrBuffer;
    ScePVoid pCbBuffer;
    ScePVoid pCrBuffer2;
    ScePVoid pCbBuffer2;
    SceInt32 iFrameHeight;
    SceInt32 iFrameWidth;
    SceInt32 iFrameBufferWidth;
    SceInt32 iUnknown3[11];
};

SceInt32 sceMpegBaseYCrCbCopyVme(ScePVoid YUVBuffer, SceInt32 *Buffer, SceInt32 Type);
SceInt32 sceMpegBaseCscInit(SceInt32 width);
SceInt32 sceMpegBaseCscVme(ScePVoid pRGBbuffer, ScePVoid pRGBbuffer2, SceInt32 width, SceMpegYCrCbBuffer* pYCrCbBuffer);
SceInt32 sceMpegbase_BEA18F91(SceMpegLLI *pLLI);

struct PspBufferInfo
{
    u8 *pucWritePositionFirstBuf;
    u32 uiWritableByteFirstBuf;
    u32 uiMinWriteByteFirstBuf;
    u32 uiReadPositionFirstBuf;
    u8 *pucWritePositionSecondBuf;
    u32 uiWritableByteSecondBuf;
    u32 uiMinWriteByteSecondBuf;
    u32 uiReadPositionSecondBuf;
};

int sceAtracGetAtracID(uint uiCodecType);
int sceAtracSetDataAndGetID(void *buf, SceSize bufsize);
int sceAtracDecodeData(int atracID, u16 *outSamples, int *outN, int *outEnd, int *outRemainFrame);
int sceAtracGetRemainFrame(int atracID, int *outRemainFrame);
int sceAtracGetStreamDataInfo(int atracID, u8** writePointer, u32* availableBytes, u32* readOffset);
int sceAtracAddStreamData(int atracID, unsigned int bytesToAdd);
int sceAtracGetBitrate(int atracID, int *outBitrate);
int sceAtracSetLoopNum(int atracID, int nloops);
int sceAtracReleaseAtracID(int atracID);
int sceAtracGetNextSample(int atracID, int *outN);
int sceAtracGetMaxSample(int atracID, int *outMax);
int sceAtracGetBufferInfoForReseting(int atracID, u32 uiSample, PspBufferInfo *pBufferInfo);
int sceAtracGetChannel(int atracID, u32 *puiChannel);
int sceAtracGetInternalErrorInfo(int atracID, int *piResult);
int sceAtracGetLoopStatus(int atracID, int *piLoopNum, u32 *puiLoopStatus);
int sceAtracGetNextDecodePosition(int atracID, u32 *puiSamplePosition);
int sceAtracGetSecondBufferInfo(int atracID, u32 *puiPosition, u32 *puiDataByte);
int sceAtracGetSoundSample(int atracID, int *piEndSample, int *piLoopStartSample, int *piLoopEndSample);
int sceAtracResetPlayPosition(int atracID, u32 uiSample, u32 uiWriteByteFirstBuf, u32 uiWriteByteSecondBuf);
int sceAtracSetData(int atracID, u8 *pucBufferAddr, u32 uiBufferByte);
int sceAtracSetHalfwayBuffer(int atracID, u8 *pucBufferAddr, u32 uiReadByte, u32 uiBufferByte);
int sceAtracSetHalfwayBufferAndGetID(u8 *pucBufferAddr, u32 uiReadByte, u32 uiBufferByte);
int sceAtracSetSecondBuffer(int atracID, u8 *pucSecondBufferAddr, u32 uiSecondBufferByte);
int sceVideocodecOpen(unsigned long *Buffer, int Type);
int sceVideocodecGetEDRAM(unsigned long *Buffer, int Type);
int sceVideocodecInit(unsigned long *Buffer, int Type);
int sceVideocodecDecode(unsigned long *Buffer, int Type);
int sceVideocodecReleaseEDRAM(unsigned long *Buffer);

struct SceMp3InitArg
{
    SceUInt32 mp3StreamStart;
    SceUInt32 unk1;
    SceUInt32 mp3StreamEnd;
    SceUInt32 unk2;
    SceVoid* mp3Buf;
    SceInt32 mp3BufSize;
    SceVoid* pcmBuf;
    SceInt32 pcmBufSize;
};

SceInt32 sceMp3ReserveMp3Handle(SceMp3InitArg* args);
SceInt32 sceMp3ReleaseMp3Handle(SceInt32 handle);
SceInt32 sceMp3InitResource();
SceInt32 sceMp3TermResource();
SceInt32 sceMp3Init(SceInt32 handle);
SceInt32 sceMp3Decode(SceInt32 handle, SceShort16** dst);
SceInt32 sceMp3GetInfoToAddStreamData(SceInt32 handle, SceUChar8** dst, SceInt32* towrite, SceInt32* srcpos);
SceInt32 sceMp3NotifyAddStreamData(SceInt32 handle, SceInt32 size);
SceInt32 sceMp3CheckStreamDataNeeded(SceInt32 handle);
SceInt32 sceMp3SetLoopNum(SceInt32 handle, SceInt32 loop);
SceInt32 sceMp3GetLoopNum(SceInt32 handle);
SceInt32 sceMp3GetSumDecodedSample(SceInt32 handle);
SceInt32 sceMp3GetMaxOutputSample(SceInt32 handle);
SceInt32 sceMp3GetSamplingRate(SceInt32 handle);
SceInt32 sceMp3GetBitRate(SceInt32 handle);
SceInt32 sceMp3GetMp3ChannelNum(SceInt32 handle);
SceInt32 sceMp3ResetPlayPosition(SceInt32 handle);

struct pspUmdInfo
{
    unsigned int size;
    unsigned int type;
};

enum pspUmdTypes
{
    PSP_UMD_TYPE_GAME = 0x10,
    PSP_UMD_TYPE_VIDEO = 0x20,
    PSP_UMD_TYPE_AUDIO = 0x40
};

enum pspUmdState
{
    PSP_UMD_NOT_PRESENT = 0x01,
    PSP_UMD_PRESENT = 0x02,
    PSP_UMD_CHANGED = 0x04,
    PSP_UMD_INITING = 0x08,
    PSP_UMD_INITED = 0x10,
    PSP_UMD_READY = 0x20
};

enum UmdDriveStat
{
    UMD_WAITFORDISC = 0x02,
    UMD_WAITFORINIT = 0x20
};

typedef int (*UmdCallback)(int unknown, int event);

int sceUmdCheckMedium(void);
int sceUmdGetDiscInfo(pspUmdInfo *info);
int sceUmdActivate(int unit, const char *drive);
int sceUmdDeactivate(int unit, const char *drive);
int sceUmdWaitDriveStat(int stat);
int sceUmdWaitDriveStatWithTimer(int stat, unsigned int timeout);
int sceUmdWaitDriveStatCB(int stat, unsigned int timeout);
int sceUmdCancelWaitDriveStat(void);
int sceUmdGetDriveStat(void);
int sceUmdGetErrorStat(void);
int sceUmdRegisterUMDCallBack(int cbid);
int sceUmdUnRegisterUMDCallBack(int cbid);
int sceUmdReplacePermit(void);
int sceUmdReplaceProhibit(void);
