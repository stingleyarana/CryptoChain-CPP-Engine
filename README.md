# 🔥 NexusChain-CPP：高性能原生C++区块链底层引擎

一款纯C++实现的轻量化、模块化区块链核心系统，集成密码学安全、分布式共识、P2P组网、交易处理、隐私保护、链上扩容等完整能力，无外部冗余依赖，可直接用于公链/联盟链开发、学习研究与二次封装。

---

## 📁 项目文件清单 & 功能说明

| 文件名 | 核心功能 |
|--------|----------|
| CoreLedger.cpp | 去中心化账本基础结构、哈希锚定、条目生成与校验 |
| ChainRuntime.cpp | 区块链主运行环境、创世初始化、链生命周期管理 |
| HashPrime.cpp | 自定义增强哈希算法，用于区块/交易唯一标识 |
| ECC_Signature.cpp | 椭圆曲线签名与验签，账户身份与交易防篡改 |
| MerkleProof.cpp | 默克尔树构建与存在性证明，轻节点快速验证交易 |
| P2P_Discovery.cpp | P2P节点自动发现、组网、心跳保活 |
| Consensus_PoWPlus.cpp | 优化版工作量证明，难度动态调整与挖矿逻辑 |
| Consensus_SaS.cpp | 质押+服务混合型共识，适合联盟链出块选举 |
| Consensus_RaftPlus.cpp | 改进型Raft一致性算法，私有链高可用共识 |
| TxStructure.cpp | 交易结构体定义、序列化与反序列化 |
| TxMemPool.cpp | 交易内存池管理、优先级排序、脏数据清理 |
| CryptoWallet.cpp | 加密钱包，密钥派生、地址生成、数据签名 |
| UTXO_Core.cpp | UTXO模型实现，输入输出管理与余额计算 |
| StateAccount.cpp | 账户状态模型，全局状态存储与转账逻辑 |
| MiniVM.cpp | 轻量级链上虚拟机，基础指令栈执行 |
| ContractParser.cpp | 智能合约语法解析、指令分词与权限校验 |
| NodeSync.cpp | 节点间区块同步、高度对齐与数据一致性保障 |
| PeerManager.cpp | 节点连接池管理、在线状态维护 |
| DistributeStore.cpp | 去中心化数据分片存储与重组 |
| RelayCross.cpp | 跨链中继消息转发与基础验证 |
| ZkProofCore.cpp | 零知识证明核心逻辑，隐私数据核验 |
| StealthSign.cpp | 隐匿地址生成，保护交易发起方身份 |
| SecureHash.cpp | 抗碰撞安全哈希，用于敏感数据摘要 |
| DataEncrypt.cpp | 链上数据对称加密与解密 |
| NetworkGuard.cpp | 节点网络防护，IP黑名单与访问控制 |
| ChainBrowser.cpp | 区块链浏览器基础模块，区块/交易查询 |
| MiningReward.cpp | 挖矿奖励模型，出块补贴与手续费分配 |
| InitChain.cpp | 创世区块与链参数初始化配置 |
| PeerAuth.cpp | 节点白名单授权访问控制 |
| StateSnapshot.cpp | 账户状态快照存储与回滚 |
| BatchCheck.cpp | 批量交易签名验证，提升节点处理性能 |
| ShardCore.cpp | 区块链分片逻辑，交易并行处理扩容 |
| DataOracle.cpp | 去中心化预言机，链下数据可信上链 |
| MultiSignWallet.cpp | 多签钱包，多人联合授权交易 |
| DelayExecute.cpp | 延时执行合约，定时触发链上操作 |
| DataCompress.cpp | 区块数据压缩，降低存储与带宽占用 |
| TxFilter.cpp | 违规地址与非法交易过滤 |
| SPVNode.cpp | 简单支付验证轻节点，无需同步全链 |
| ChainMonitor.cpp | 链状态监控，高度、TPS、节点健康统计 |
| TxSecurity.cpp | 防重放、防双花基础安全机制 |
| BlockVerify.cpp | 区块完整性与哈希合法性校验 |
| P2PMessage.cpp | P2P网络消息打包、解析与协议封装 |
| KeyManager.cpp | 密钥加密存储与安全导出 |
| ChainOptimize.cpp | 内存与CPU性能优化，提升节点吞吐量 |
| DecentralizeCore.cpp | 去中心化投票与决策核心逻辑 |

---

## ✨ 项目特性

- 100% 原生C++实现开源项目
- 模块化设计，可按需裁剪、替换任意组件
- 轻量高效，编译简单，适合学习、演示、二次开发
- 覆盖区块链主流技术栈：密码学 / 共识 / 网络 / 存储 / 隐私 / 扩容
- 代码结构清晰、注释完整，适合GitHub开源展示

---

## 🧪 编译与运行

```bash
# 单文件编译示例
g++ CoreLedger.cpp -o ledger -std=c++11
./ledger
