#include <hv/WebSocketServer.h>

#include <list>
#include <thread>
#include <optional>

class Net {
    private:
        //std::list<WebSocketChannelPtr> _channels;

        // pour gérer les noms de client :
        std::list<WebSocketChannelPtr> _pendings;
        std::map<WebSocketChannelPtr, std::string> _connections;

    public:
        Net() = default;
        Net(const Net &) = delete;

        void add(const WebSocketChannelPtr & c, const std::string & name) {
            _connections.insert(std::pair<WebSocketChannelPtr, std::string>(c, name));
        }

        void del(const WebSocketChannelPtr & c) {
            auto it = std::find(_connections.begin(), _connections.end(), c);
            if (it != _connections.end())
                _connections.erase(it);
        }

        void map(std::function<void(const WebSocketChannelPtr &)> f) {
            for (auto it : _connections)
                f(it.first);
        }

        // pour gérer les noms de client :
        bool giveName(const WebSocketChannelPtr& c, const std::string& n){
            for (auto it : _connections)
                if(it.second == n){
                    return true;
                }
            return false;
        }
        bool isPending(const WebSocketChannelPtr& c) const{
            auto it = std::find_if(_pendings.begin(), _pendings.end, c);
            return it != _pendings.end();
        }
        std::optional<std::string> findName(const WebSocketChannelPtr& c) const{
            auto it = std::find_if(_connections.begin(), _connections.end(), c);
            if (it != _connections.end())
                return it->second;
            else
                return {}
        }

};

