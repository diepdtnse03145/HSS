#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtAndroidExtras>

static void fromJavaOne(JNIEnv *env, jobject thiz, jint x)
{
    Q_UNUSED(env)
    Q_UNUSED(thiz)
    qDebug() << x << "< 100";
}

void registerNativeMethods() {
    JNINativeMethod methods[] {{"callNativeOne", "(I)V", reinterpret_cast<void *>(fromJavaOne)}};

    QAndroidJniObject javaClass = QAndroidJniObject::
            callStaticObjectMethod("org/hss/hss/MyActivity",
                                   "getIns",
                                   "()Lorg/hss/hss/MyActivity;");

    QAndroidJniEnvironment env;
    jclass objectClass = env->GetObjectClass(javaClass.object<jobject>());
    env->RegisterNatives(objectClass,
                         methods,
                         sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(objectClass);
}
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    registerNativeMethods();
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
