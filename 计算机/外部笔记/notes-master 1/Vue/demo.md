<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>vue-demo</title>
    <link href="https://cdn.bootcss.com/twitter-bootstrap/4.3.1/css/bootstrap.min.css" rel="stylesheet">
    <script src="https://cdn.jsdelivr.net/npm/vue@2.6.6/dist/vue.min.js"></script>
    <script src="https://unpkg.com/axios/dist/axios.min.js"></script>
</head>

<body>
    <div id="app" class="container">
        <h1>{{ title }}</h1>
        <div v-if="loading" class="alert alert-info">加载中...</div>
        <div v-if="error" class="alert alert-danger">加载失败：{{ errorMsg }}</div>
        <ul class="list-unstyled" v-if="!loading && !error">
            <li class="media" v-for="item in articles">
                <a v-bind:href="item.url" target="_blank">
                    <div class="media-body">
                        <h5 class="mt-0 mb-1">{{ item.title || item.desc }}</h5>
                        <p v-if="item.content" class="text-muted">{{ item.content.substring(0, 100) }}...</p>
                    </div>
                </a>
            </li>
        </ul>
    </div>
</body>
<script>
    var app = new Vue({
        el: '#app',
        data: {
            title: '资讯列表',
            // 方案1: 使用 JSONPlaceholder 免费 API（测试用）
            apiURL: 'https://jsonplaceholder.typicode.com/posts',
            // 方案2: 如果上面的不行，可以用这个
            // apiURL: 'https://api.github.com/repos/vuejs/vue/commits',
            articles: [],
            loading: false,
            error: false,
            errorMsg: ''
        },
        mounted: function () {
            this.getData();
        },
        methods: {
            getData: function () {
                this.loading = true;
                this.error = false;
                
                axios.get(this.apiURL)
                    .then(response => {
                        // 根据不同 API 格式处理数据
                        let rawData = response.data;
                        
                        // JSONPlaceholder 的数据格式处理
                        if (Array.isArray(rawData) && rawData[0] && rawData[0].title) {
                            this.articles = rawData.slice(0, 20).map(item => ({
                                title: item.title,
                                content: item.body,
                                url: `https://jsonplaceholder.typicode.com/posts/${item.id}`
                            }));
                        } 
                        // GitHub API 格式处理
                        else if (Array.isArray(rawData) && rawData[0] && rawData[0].commit) {
                            this.articles = rawData.slice(0, 20).map(item => ({
                                title: item.commit.message.split('\n')[0],
                                desc: item.commit.message,
                                url: item.html_url
                            }));
                        }
                        // 其他格式的处理
                        else {
                            this.articles = rawData;
                        }
                        
                        this.loading = false;
                    })
                    .catch(error => {
                        console.log('API请求失败:', error);
                        this.error = true;
                        this.errorMsg = '无法获取数据，请检查网络连接';
                        this.loading = false;
                        // 加载模拟数据作为备选
                        this.loadMockData();
                    })
            },
            loadMockData: function() {
                // 模拟数据
                this.articles = [
                    { title: 'Vue 3 正式发布', content: 'Vue 3 带来了许多新特性...', url: 'https://vuejs.org/' },
                    { title: 'Vue Router 4 发布', content: '支持 Vue 3 的路由管理...', url: 'https://router.vuejs.org/' },
                    { title: 'Pinia 成为 Vue 官方状态管理工具', content: '新一代状态管理方案...', url: 'https://pinia.vuejs.org/' },
                    { title: 'Vue 生态工具 Vite 快速入门', content: '新一代前端构建工具...', url: 'https://vitejs.dev/' },
                    { title: 'Nuxt 3 全栈框架介绍', content: '基于 Vue 3 的 SSR 框架...', url: 'https://nuxt.com/' },
                ];
                this.errorMsg = 'API不可用，当前显示模拟数据';
            }
        },
    })
</script>

</html>